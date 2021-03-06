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

#ifndef GLOBALHOTKEY_P_H
#define GLOBALHOTKEY_P_H

#include "globalhotkey.h"
#include <QObject>
#include <QAbstractNativeEventFilter>

class GlobalHotkey::GlobalHotkeyPrivate : public QObject, public QAbstractNativeEventFilter
{
	Q_OBJECT

public:
	GlobalHotkeyPrivate(QObject* parent = 0);

    bool registerNativeHotkey(const int hk);
	void unregisterNativeHotkeys();

	bool nativeEventFilter(const QByteArray&, void*, long*) override;

signals:
	 void hotKeyPressed();
};

#endif // GLOBALHOTKEY_P_H
