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
#include "qumlanyreceiveeventobject_p.h"

#include <QtUml/QUmlAnyReceiveEvent>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>

QT_BEGIN_NAMESPACE

QUmlAnyReceiveEventObject::QUmlAnyReceiveEventObject(QUmlAnyReceiveEvent *qModelingObject)
{
    setProperty("modelingObject", QVariant::fromValue(qModelingObject));
}

QUmlAnyReceiveEventObject::~QUmlAnyReceiveEventObject()
{
    if (!property("deletingFromModelingObject").isValid()) {
        qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->deletingFromQObject = true;
        delete qmodelingobjectproperty_cast<QUmlComment *>(this);
    }
}

// OWNED ATTRIBUTES [Element]

const QSet<QObject *> QUmlAnyReceiveEventObject::ownedComment() const
{
    QSet<QObject *> set;
    foreach (QUmlComment *element, qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->ownedComment())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlAnyReceiveEventObject::ownedElement() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->ownedElement())
        set.insert(element->asQObject());
    return set;
}

QObject *QUmlAnyReceiveEventObject::owner() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->owner()->asQObject();
}

// OWNED ATTRIBUTES [ParameterableElement]

QObject *QUmlAnyReceiveEventObject::owningTemplateParameter() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->owningTemplateParameter()->asQObject();
}

QObject *QUmlAnyReceiveEventObject::templateParameter() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->templateParameter()->asQObject();
}

// OWNED ATTRIBUTES [NamedElement]

const QSet<QObject *> QUmlAnyReceiveEventObject::clientDependency() const
{
    QSet<QObject *> set;
    foreach (QUmlDependency *element, qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->clientDependency())
        set.insert(element->asQObject());
    return set;
}

QString QUmlAnyReceiveEventObject::name() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->name();
}

QObject *QUmlAnyReceiveEventObject::nameExpression() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->nameExpression()->asQObject();
}

QObject *QUmlAnyReceiveEventObject::namespace_() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->namespace_()->asQObject();
}

QString QUmlAnyReceiveEventObject::qualifiedName() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->qualifiedName();
}
// OWNED ATTRIBUTES [PackageableElement]

QtUml::VisibilityKind QUmlAnyReceiveEventObject::visibility() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->visibility();
}

// OPERATIONS [Element]

QSet<QObject *> QUmlAnyReceiveEventObject::allOwnedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->allOwnedElements())
        set.insert(element->asQObject());
    return set;
}

bool QUmlAnyReceiveEventObject::mustBeOwned() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->mustBeOwned();
}

// OPERATIONS [ParameterableElement]

bool QUmlAnyReceiveEventObject::isCompatibleWith(QObject *p) const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->isCompatibleWith(qmodelingobjectproperty_cast<QUmlParameterableElement *>(p));
}

bool QUmlAnyReceiveEventObject::isTemplateParameter() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->isTemplateParameter();
}

// OPERATIONS [NamedElement]

QList<QObject *> QUmlAnyReceiveEventObject::allNamespaces() const
{
    QList<QObject *> set;
    foreach (QUmlNamespace *element, qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->allNamespaces())
        set.append(element->asQObject());
    return set;
}

QSet<QObject *> QUmlAnyReceiveEventObject::allOwningPackages() const
{
    QSet<QObject *> set;
    foreach (QUmlPackage *element, qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->allOwningPackages())
        set.insert(element->asQObject());
    return set;
}

bool QUmlAnyReceiveEventObject::isDistinguishableFrom(QObject *n, QObject *ns) const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->isDistinguishableFrom(qmodelingobjectproperty_cast<QUmlNamedElement *>(n), qmodelingobjectproperty_cast<QUmlNamespace *>(ns));
}

QString QUmlAnyReceiveEventObject::separator() const
{
    return qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->separator();
}

// SLOTS FOR OWNED ATTRIBUTES [Element]

void QUmlAnyReceiveEventObject::addOwnedComment(QObject *ownedComment)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->addOwnedComment(qmodelingobjectproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlAnyReceiveEventObject::removeOwnedComment(QObject *ownedComment)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->removeOwnedComment(qmodelingobjectproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlAnyReceiveEventObject::addOwnedElement(QObject *ownedElement)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->addOwnedElement(qmodelingobjectproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlAnyReceiveEventObject::removeOwnedElement(QObject *ownedElement)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->removeOwnedElement(qmodelingobjectproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlAnyReceiveEventObject::setOwner(QObject *owner)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->setOwner(qmodelingobjectproperty_cast<QUmlElement *>(owner));
}

// SLOTS FOR OWNED ATTRIBUTES [ParameterableElement]

void QUmlAnyReceiveEventObject::setOwningTemplateParameter(QObject *owningTemplateParameter)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->setOwningTemplateParameter(qmodelingobjectproperty_cast<QUmlTemplateParameter *>(owningTemplateParameter));
}

void QUmlAnyReceiveEventObject::setTemplateParameter(QObject *templateParameter)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->setTemplateParameter(qmodelingobjectproperty_cast<QUmlTemplateParameter *>(templateParameter));
}

// SLOTS FOR OWNED ATTRIBUTES [NamedElement]

void QUmlAnyReceiveEventObject::addClientDependency(QObject *clientDependency)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->addClientDependency(qmodelingobjectproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlAnyReceiveEventObject::removeClientDependency(QObject *clientDependency)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->removeClientDependency(qmodelingobjectproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlAnyReceiveEventObject::setName(QString name)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->setName(name);
}
    
void QUmlAnyReceiveEventObject::setNameExpression(QObject *nameExpression)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->setNameExpression(qmodelingobjectproperty_cast<QUmlStringExpression *>(nameExpression));
}

void QUmlAnyReceiveEventObject::setNamespace(QObject *namespace_)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->setNamespace(qmodelingobjectproperty_cast<QUmlNamespace *>(namespace_));
}

void QUmlAnyReceiveEventObject::setQualifiedName(QString qualifiedName)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->setQualifiedName(qualifiedName);
}
    // SLOTS FOR OWNED ATTRIBUTES [PackageableElement]

void QUmlAnyReceiveEventObject::setVisibility(QtUml::VisibilityKind visibility)
{
    qmodelingobjectproperty_cast<QUmlAnyReceiveEvent *>(this)->setVisibility(visibility);
}
    
QT_END_NAMESPACE
