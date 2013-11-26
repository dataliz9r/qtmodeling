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
#ifndef JAVASCRIPTCONSOLEPLUGIN_H
#define JAVASCRIPTCONSOLEPLUGIN_H

#include <duseinterfaces/iplugin.h>

#include <QtScript/QScriptEngine>

class QListView;

class QModelingObject;

class QModelingObjectView;
class QModelingObjectModel;
class QModelingObjectPropertyEditor;
class QModelingObjectPropertyModel;

namespace Ui {
    class JavaScriptConsole;
}

class JavaScriptConsolePlugin : public DuSE::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.liveblue.DuSE.IPlugin" FILE "javascriptconsole.json")

public:
    JavaScriptConsolePlugin(QObject *parent = 0);
    virtual ~JavaScriptConsolePlugin();

    virtual bool initialize(DuSE::ICore *core);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

public Q_SLOTS:
    void setSelfProperty(QModelingObject *modelingObject);
    void setRootAndInputProperties(QList<QModelingObject *> modelingObjects);

private Q_SLOTS:
    void evaluate();

private:
    Ui::JavaScriptConsole *_javaScriptConsole;
    QListView *_codeCompletionView;
    QScriptEngine _engine;
};

#endif // JAVASCRIPTCONSOLEPLUGIN_H
