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
#include "qumlliteralunlimitednatural.h"
#include "qumlliteralunlimitednatural_p.h"

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QUmlLiteralUnlimitedNaturalPrivate::QUmlLiteralUnlimitedNaturalPrivate() :
    value(0)
{
}

QUmlLiteralUnlimitedNaturalPrivate::~QUmlLiteralUnlimitedNaturalPrivate()
{
}

/*!
    \class QUmlLiteralUnlimitedNatural

    \inmodule QtUml

    \brief A literal unlimited natural is a specification of an unlimited natural number.
 */

QUmlLiteralUnlimitedNatural::QUmlLiteralUnlimitedNatural(QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlLiteralSpecification(*new QUmlLiteralUnlimitedNaturalPrivate, wrapper, parent)
{
    setPropertyData();
}

QUmlLiteralUnlimitedNatural::QUmlLiteralUnlimitedNatural(QUmlLiteralUnlimitedNaturalPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlLiteralSpecification(dd, wrapper, parent)
{
    setPropertyData();
}

QUmlLiteralUnlimitedNatural::~QUmlLiteralUnlimitedNatural()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QUmlLiteralUnlimitedNatural
// ---------------------------------------------------------------

/*!
    The specified UnlimitedNatural value.
 */
qint32 QUmlLiteralUnlimitedNatural::value() const
{
    // This is a read-write attribute

    Q_D(const QUmlLiteralUnlimitedNatural);
    return d->value;
}

void QUmlLiteralUnlimitedNatural::setValue(qint32 value)
{
    // This is a read-write attribute

    Q_D(QUmlLiteralUnlimitedNatural);
    if (d->value != value) {
        d->value = value;
    }
    d->modifiedResettableProperties << QString::fromLatin1("value");
}

void QUmlLiteralUnlimitedNatural::unsetValue()
{
    setValue(0);
    Q_D(QUmlLiteralUnlimitedNatural);
    d->modifiedResettableProperties.removeAll(QString::fromLatin1("value"));
}

/*!
    The query isComputable() is redefined to be true.
 */
bool QUmlLiteralUnlimitedNatural::isComputable() const
{
    qWarning("QUmlLiteralUnlimitedNatural::isComputable: operation to be implemented");

    return bool(); // change here to your derived return
}

/*!
    The query unlimitedValue() gives the value.
 */
qint32 QUmlLiteralUnlimitedNatural::unlimitedValue() const
{
    qWarning("QUmlLiteralUnlimitedNatural::unlimitedValue: operation to be implemented");

    return qint32(); // change here to your derived return
}

void QUmlLiteralUnlimitedNatural::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlLiteralUnlimitedNatural")][QString::fromLatin1("value")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlLiteralUnlimitedNatural")][QString::fromLatin1("value")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlLiteralUnlimitedNatural")][QString::fromLatin1("value")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The specified UnlimitedNatural value.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlLiteralUnlimitedNatural")][QString::fromLatin1("value")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlLiteralUnlimitedNatural")][QString::fromLatin1("value")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QUmlLiteralUnlimitedNatural")][QString::fromLatin1("value")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QUmlLiteralSpecification::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qumlliteralunlimitednatural.cpp"
