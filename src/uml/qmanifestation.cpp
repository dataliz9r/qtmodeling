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

#include "qmanifestation.h"
#include "qmanifestation_p.h"

#include <QtUml/QPackageableElement>

#include <QtWrappedObjects/QtWrappedObjectsEnumerations>

QT_BEGIN_NAMESPACE_QTUML

QManifestationPrivate::QManifestationPrivate() :
    utilizedElement(0)
{
}

QManifestationPrivate::~QManifestationPrivate()
{
}

/*!
    \class QManifestation

    \inmodule QtUml

    \brief A manifestation is the concrete physical rendering of one or more model elements by an artifact.
 */

QManifestation::QManifestation(QWrappedObject *wrapper, QWrappedObject *parent) :
    QAbstraction(*new QManifestationPrivate, wrapper, parent)
{
    setPropertyData();
}

QManifestation::QManifestation(QManifestationPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QAbstraction(dd, wrapper, parent)
{
    setPropertyData();
}

QManifestation::~QManifestation()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QManifestation
// ---------------------------------------------------------------

/*!
    The model element that is utilized in the manifestation in an Artifact.
 */
QPackageableElement *QManifestation::utilizedElement() const
{
    // This is a read-write association end

    Q_D(const QManifestation);
    return d->utilizedElement;
}

void QManifestation::setUtilizedElement(QPackageableElement *utilizedElement)
{
    // This is a read-write association end

    Q_D(QManifestation);
    if (d->utilizedElement != utilizedElement) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QDependency *>(this))->removeSupplier(qwrappedobject_cast<QNamedElement *>(d->utilizedElement));

        d->utilizedElement = utilizedElement;

        // Adjust subsetted property(ies)
        if (utilizedElement) {
            (qwrappedobject_cast<QDependency *>(this))->addSupplier(qwrappedobject_cast<QNamedElement *>(utilizedElement));
        }
    }
}

void QManifestation::registerMetaTypes() const
{
    qRegisterMetaType<QPackageableElement *>("QPackageableElement *");
    qRegisterMetaType<QSet<QPackageableElement *>>("QSet<QPackageableElement *>");
    qRegisterMetaType<QList<QPackageableElement *>>("QList<QPackageableElement *>");

    QAbstraction::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

void QManifestation::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QManifestation")][QString::fromLatin1("utilizedElement")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QManifestation")][QString::fromLatin1("utilizedElement")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QManifestation")][QString::fromLatin1("utilizedElement")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The model element that is utilized in the manifestation in an Artifact.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QManifestation")][QString::fromLatin1("utilizedElement")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QManifestation")][QString::fromLatin1("utilizedElement")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QDependency::suppliers");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QManifestation")][QString::fromLatin1("utilizedElement")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QAbstraction::setPropertyData();
}

// Overriden methods for subsetted properties

void QManifestation::addSupplier(QWrappedObjectPointer<QPackageableElement> utilizedElement)
{
    setUtilizedElement(utilizedElement);
}

void QManifestation::removeSupplier(QWrappedObjectPointer<QPackageableElement> utilizedElement)
{
    Q_UNUSED(utilizedElement);
    setUtilizedElement(0);
}

#include "moc_qmanifestation.cpp"

QT_END_NAMESPACE_QTUML

