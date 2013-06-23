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
#include "qumlinstancevalue.h"
#include "qumlinstancevalue_p.h"

#include <QtUml/QUmlInstanceSpecification>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QUmlInstanceValuePrivate::QUmlInstanceValuePrivate() :
    instance(0)
{
}

QUmlInstanceValuePrivate::~QUmlInstanceValuePrivate()
{
}

/*!
    \class QUmlInstanceValue

    \inmodule QtUml

    \brief An instance value is a value specification that identifies an instance.
 */

QUmlInstanceValue::QUmlInstanceValue(QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlValueSpecification(*new QUmlInstanceValuePrivate, wrapper, parent)
{
    setPropertyData();
}

QUmlInstanceValue::QUmlInstanceValue(QUmlInstanceValuePrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlValueSpecification(dd, wrapper, parent)
{
    setPropertyData();
}

QUmlInstanceValue::~QUmlInstanceValue()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QUmlInstanceValue
// ---------------------------------------------------------------

/*!
    The instance that is the specified value.
 */
QUmlInstanceSpecification *QUmlInstanceValue::instance() const
{
    // This is a read-write association end

    Q_D(const QUmlInstanceValue);
    return d->instance;
}

void QUmlInstanceValue::setInstance(QUmlInstanceSpecification *instance)
{
    // This is a read-write association end

    Q_D(QUmlInstanceValue);
    if (d->instance != instance) {
        d->instance = instance;
    }
}

void QUmlInstanceValue::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlInstanceValue")][QString::fromLatin1("instance")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlInstanceValue")][QString::fromLatin1("instance")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlInstanceValue")][QString::fromLatin1("instance")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The instance that is the specified value.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlInstanceValue")][QString::fromLatin1("instance")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlInstanceValue")][QString::fromLatin1("instance")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlInstanceValue")][QString::fromLatin1("instance")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QUml");

    QUmlValueSpecification::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qumlinstancevalue.cpp"
