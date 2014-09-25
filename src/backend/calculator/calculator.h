// albert - a simple application launcher for linux
// Copyright (C) 2014 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "abstractserviceprovider.h"
#include "singleton.h"
#include <string>
#include <vector>
#include <unistd.h>


/*********************************************************************/
class Calculator : public AbstractServiceProvider, public Singleton<Calculator>
{
	friend class Singleton<Calculator>;
public:
	class Item;

	void query(const std::string&, std::vector<AbstractServiceProvider::Item*>*) override;

protected:
	Calculator();
	~Calculator();

	Item *_theOneAndOnly;
	std::vector<Item*> _searchEngines;
};

/*********************************************************************/
class Calculator::Item : public AbstractServiceProvider::Item
{
	friend class Calculator;

public:
	Item(){}
	~Item(){}

	inline std::string title()            const override {return _result;}
	inline std::string complete()         const override {return _query;}
	inline std::string infoText()         const override {return "Result of '"+_query+"'";}
	void               action(Action)           override;
	std::string        actionText(Action) const override;
	QIcon              icon()         const override;

protected:
	std::string _query;
	std::string _result;
};
#endif // CALCULATOR_H
