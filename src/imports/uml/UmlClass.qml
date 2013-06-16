/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
import QtQuick 2.0

Rectangle {
    property alias name: nameSlot.label
    height: nameSlot.height + propertiesSlot.height; width: propertiesColumn.width
    UmlSlot {
        width: propertiesSlot.width
        id: nameSlot
    }
    UmlSlot {
        anchors.top: nameSlot.bottom
        anchors.topMargin: -1
        id: propertiesSlot
        height: propertiesColumn.height + 10; width: propertiesColumn.width + 20
        Column {
            id: propertiesColumn
            anchors.centerIn: parent
        }
    }
    MouseArea {
        id: dragArea
        anchors.fill: parent

        drag.target: parent
        drag.minimumX: 0
        drag.minimumY: 0
    }
    Component.onCompleted: {
        if (element) {
            name = element.name;
            nameSlot.labelFont.italic = element.isAbstract;
            for (var i = 0; i < attributes.length; ++i) {
                var visibility;
                switch (attributes[i].visibility) {
                    case 0: visibility = "+"; break;
                    case 1: visibility = "-"; break;
                    case 2: visibility = "#"; break;
                    case 3: visibility = "~"; break;
                }
                var attributeString = visibility + attributes[i].name;
                if (attributes[i].type)
                    attributeString += ': ' + attributes[i].type.name;
                Qt.createQmlObject('import QtQuick 2.0; Text {text: "' + attributeString + '"}', propertiesColumn, 'dynamicAttributes');
            }
        }
    }
}
