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

#include "qreclassifyobjectaction.h"
#include "qreclassifyobjectaction_p.h"

#include <QtUml/QClassifier>
#include <QtUml/QInputPin>

QT_BEGIN_NAMESPACE_QTUML

QReclassifyObjectActionPrivate::QReclassifyObjectActionPrivate() :
    isReplaceAll(false),
    oldClassifiers(new QSet<QClassifier *>),
    object(0),
    newClassifiers(new QSet<QClassifier *>)
{
}

QReclassifyObjectActionPrivate::~QReclassifyObjectActionPrivate()
{
    delete oldClassifiers;
    delete newClassifiers;
}

/*!
    \class QReclassifyObjectAction

    \inmodule QtUml

    \brief A reclassify object action is an action that changes which classifiers classify an object.
 */

QReclassifyObjectAction::QReclassifyObjectAction(QObject *parent) :
    QAction(*new QReclassifyObjectActionPrivate, parent)
{
}

QReclassifyObjectAction::QReclassifyObjectAction(QReclassifyObjectActionPrivate &dd, QObject *parent) :
    QAction(dd, parent)
{
}

QReclassifyObjectAction::~QReclassifyObjectAction()
{
}

/*!
    Specifies whether existing classifiers should be removed before adding the new classifiers.
 */
bool QReclassifyObjectAction::isReplaceAll() const
{
    // This is a read-write attribute

    Q_D(const QReclassifyObjectAction);
    return d->isReplaceAll;
}

void QReclassifyObjectAction::setReplaceAll(bool isReplaceAll)
{
    // This is a read-write attribute

    Q_D(QReclassifyObjectAction);
    if (d->isReplaceAll != isReplaceAll) {
        d->isReplaceAll = isReplaceAll;
    }
}

/*!
    A set of classifiers to be removed from the classifiers of the object.
 */
const QSet<QClassifier *> *QReclassifyObjectAction::oldClassifiers() const
{
    // This is a read-write association end

    Q_D(const QReclassifyObjectAction);
    return d->oldClassifiers;
}

void QReclassifyObjectAction::addOldClassifier(QClassifier *oldClassifier)
{
    // This is a read-write association end

    Q_D(QReclassifyObjectAction);
    if (!d->oldClassifiers->contains(oldClassifier)) {
        d->oldClassifiers->insert(oldClassifier);
    }
}

void QReclassifyObjectAction::removeOldClassifier(QClassifier *oldClassifier)
{
    // This is a read-write association end

    Q_D(QReclassifyObjectAction);
    if (d->oldClassifiers->contains(oldClassifier)) {
        d->oldClassifiers->remove(oldClassifier);
    }
}

/*!
    Holds the object to be reclassified.
 */
QInputPin *QReclassifyObjectAction::object() const
{
    // This is a read-write association end

    Q_D(const QReclassifyObjectAction);
    return d->object;
}

void QReclassifyObjectAction::setObject(QInputPin *object)
{
    // This is a read-write association end

    Q_D(QReclassifyObjectAction);
    if (d->object != object) {
        // Adjust subsetted property(ies)
        d->QActionPrivate::removeInput(dynamic_cast<QInputPin *>(d->object));

        d->object = object;

        // Adjust subsetted property(ies)
        if (object) {
            d->QActionPrivate::addInput(dynamic_cast<QInputPin *>(object));
        }
    }
}

/*!
    A set of classifiers to be added to the classifiers of the object.
 */
const QSet<QClassifier *> *QReclassifyObjectAction::newClassifiers() const
{
    // This is a read-write association end

    Q_D(const QReclassifyObjectAction);
    return d->newClassifiers;
}

void QReclassifyObjectAction::addNewClassifier(QClassifier *newClassifier)
{
    // This is a read-write association end

    Q_D(QReclassifyObjectAction);
    if (!d->newClassifiers->contains(newClassifier)) {
        d->newClassifiers->insert(newClassifier);
    }
}

void QReclassifyObjectAction::removeNewClassifier(QClassifier *newClassifier)
{
    // This is a read-write association end

    Q_D(QReclassifyObjectAction);
    if (d->newClassifiers->contains(newClassifier)) {
        d->newClassifiers->remove(newClassifier);
    }
}

#include "moc_qreclassifyobjectaction.cpp"

QT_END_NAMESPACE_QTUML

