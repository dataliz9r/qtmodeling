/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qacceptcallaction.h"
#include "qacceptcallaction_p.h"

#include <QtUml/QOutputPin>

#include <QtWrappedObjects/QtWrappedObjectsEnumerations>

QT_BEGIN_NAMESPACE_QTUML

QAcceptCallActionPrivate::QAcceptCallActionPrivate() :
    returnInformation(0)
{
}

QAcceptCallActionPrivate::~QAcceptCallActionPrivate()
{
}

/*!
    \class QAcceptCallAction

    \inmodule QtUml

    \brief An accept call action is an accept event action representing the receipt of a synchronous call request. In addition to the normal operation parameters, the action produces an output that is needed later to supply the information to the reply action necessary to return control to the caller. This action is for synchronous calls. If it is used to handle an asynchronous call, execution of the subsequent reply action will complete immediately with no effects.
 */

QAcceptCallAction::QAcceptCallAction(QWrappedObject *wrapper, QWrappedObject *parent) :
    QAcceptEventAction(*new QAcceptCallActionPrivate, wrapper, parent)
{
    setPropertyData();
}

QAcceptCallAction::QAcceptCallAction(QAcceptCallActionPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QAcceptEventAction(dd, wrapper, parent)
{
    setPropertyData();
}

QAcceptCallAction::~QAcceptCallAction()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QAcceptCallAction
// ---------------------------------------------------------------

/*!
    Pin where a value is placed containing sufficient information to perform a subsequent reply and return control to the caller. The contents of this value are opaque. It can be passed and copied but it cannot be manipulated by the model.
 */
QOutputPin *QAcceptCallAction::returnInformation() const
{
    // This is a read-write association end

    Q_D(const QAcceptCallAction);
    return d->returnInformation;
}

void QAcceptCallAction::setReturnInformation(QOutputPin *returnInformation)
{
    // This is a read-write association end

    Q_D(QAcceptCallAction);
    if (d->returnInformation != returnInformation) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QActionPrivate *>(d))->removeOutput(qwrappedobject_cast<QOutputPin *>(d->returnInformation));

        d->returnInformation = returnInformation;

        // Adjust subsetted property(ies)
        if (returnInformation) {
            (qwrappedobject_cast<QActionPrivate *>(d))->addOutput(qwrappedobject_cast<QOutputPin *>(returnInformation));
        }
    }
}

void QAcceptCallAction::registerMetaTypes() const
{
    qRegisterMetaType<QOutputPin *>("QOutputPin *");
    qRegisterMetaType<QSet<QOutputPin *>>("QSet<QOutputPin *>");
    qRegisterMetaType<QList<QOutputPin *>>("QList<QOutputPin *>");

    QAcceptEventAction::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

void QAcceptCallAction::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QAcceptCallAction")][QString::fromLatin1("returnInformation")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QAcceptCallAction")][QString::fromLatin1("returnInformation")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QAcceptCallAction")][QString::fromLatin1("returnInformation")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Pin where a value is placed containing sufficient information to perform a subsequent reply and return control to the caller. The contents of this value are opaque. It can be passed and copied but it cannot be manipulated by the model.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QAcceptCallAction")][QString::fromLatin1("returnInformation")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QAcceptCallAction")][QString::fromLatin1("returnInformation")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QAction::outputs");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QAcceptCallAction")][QString::fromLatin1("returnInformation")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QAcceptEventAction::setPropertyData();
}

#include "moc_qacceptcallaction.cpp"

QT_END_NAMESPACE_QTUML

