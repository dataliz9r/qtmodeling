/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtModelingWidgets module of the Qt Toolkit.
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
#ifndef QMODELINGOBJECTPROPERTYMODEL_H
#define QMODELINGOBJECTPROPERTYMODEL_H

#include <QtModelingWidgets/QtModelingWidgetsGlobal>

#include <QtCore/QAbstractItemModel>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtModelingWidgets)

class QModelingObject;
class QModelingObjectPropertyModelPrivate;

class Q_MODELINGWIDGETS_EXPORT QModelingObjectPropertyModel : public QAbstractItemModel
{
    Q_OBJECT

    Q_DISABLE_COPY(QModelingObjectPropertyModel)
    Q_DECLARE_PRIVATE(QModelingObjectPropertyModel)

public:
    explicit QModelingObjectPropertyModel(QObject *parent = 0);

    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &child) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex & index) const;

    QObject *modelingObject() const;

public Q_SLOTS:
    void setModelingObject(QModelingObject *modelingObject, QModelIndex index);

Q_SIGNALS:
    void indexChanged(const QModelIndex &modelingObjectIndex);

private:
    int propertyGroupIndex(QString *property) const;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QMODELINGOBJECTPROPERTYMODEL_H

