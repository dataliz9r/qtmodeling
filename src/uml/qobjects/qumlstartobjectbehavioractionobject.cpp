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
#include "qumlstartobjectbehavioractionobject_p.h"

#include <QtUml/QUmlStartObjectBehaviorAction>
#include <QtUml/QUmlActivity>
#include <QtUml/QUmlActivityEdge>
#include <QtUml/QUmlActivityGroup>
#include <QtUml/QUmlActivityNode>
#include <QtUml/QUmlActivityPartition>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlExceptionHandler>
#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlInterruptibleActivityRegion>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOutputPin>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPort>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuredActivityNode>

QT_BEGIN_NAMESPACE

QUmlStartObjectBehaviorActionObject::QUmlStartObjectBehaviorActionObject(QUmlStartObjectBehaviorAction *qModelingObject)
{
    setProperty("modelingObject", QVariant::fromValue(static_cast<QModelingObject *>(qModelingObject)));
}

QUmlStartObjectBehaviorActionObject::~QUmlStartObjectBehaviorActionObject()
{
    if (!property("deletingFromModelingObject").isValid()) {
        qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->deletingFromQObject = true;
        delete qmodelingobjectproperty_cast<QUmlComment *>(this);
    }
}

// OWNED ATTRIBUTES [Element]

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::ownedComments() const
{
    QSet<QObject *> set;
    foreach (QUmlComment *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->ownedComments())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::ownedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->ownedElements())
        set.insert(element->asQObject());
    return set;
}

QObject *QUmlStartObjectBehaviorActionObject::owner() const
{
    if (!qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->owner())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->owner()->asQObject();
}

// OWNED ATTRIBUTES [NamedElement]

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::clientDependencies() const
{
    QSet<QObject *> set;
    foreach (QUmlDependency *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->clientDependencies())
        set.insert(element->asQObject());
    return set;
}

QString QUmlStartObjectBehaviorActionObject::name() const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->name();
}

QObject *QUmlStartObjectBehaviorActionObject::nameExpression() const
{
    if (!qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->nameExpression())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->nameExpression()->asQObject();
}

QObject *QUmlStartObjectBehaviorActionObject::namespace_() const
{
    if (!qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->namespace_())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->namespace_()->asQObject();
}

QString QUmlStartObjectBehaviorActionObject::qualifiedName() const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->qualifiedName();
}

QtUml::VisibilityKind QUmlStartObjectBehaviorActionObject::visibility() const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->visibility();
}

// OWNED ATTRIBUTES [RedefinableElement]

bool QUmlStartObjectBehaviorActionObject::isLeaf() const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->isLeaf();
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::redefinedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlRedefinableElement *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->redefinedElements())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::redefinitionContexts() const
{
    QSet<QObject *> set;
    foreach (QUmlClassifier *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->redefinitionContexts())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [ActivityNode]

QObject *QUmlStartObjectBehaviorActionObject::activity() const
{
    if (!qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->activity())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->activity()->asQObject();
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::inGroups() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityGroup *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->inGroups())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::inInterruptibleRegions() const
{
    QSet<QObject *> set;
    foreach (QUmlInterruptibleActivityRegion *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->inInterruptibleRegions())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::inPartitions() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityPartition *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->inPartitions())
        set.insert(element->asQObject());
    return set;
}

QObject *QUmlStartObjectBehaviorActionObject::inStructuredNode() const
{
    if (!qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->inStructuredNode())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->inStructuredNode()->asQObject();
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::incomings() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityEdge *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->incomings())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::outgoings() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityEdge *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->outgoings())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::redefinedNodes() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityNode *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->redefinedNodes())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [ExecutableNode]

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::handlers() const
{
    QSet<QObject *> set;
    foreach (QUmlExceptionHandler *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->handlers())
        set.insert(element->asQObject());
    return set;
}

// OWNED ATTRIBUTES [Action]

QObject *QUmlStartObjectBehaviorActionObject::context() const
{
    if (!qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->context())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->context()->asQObject();
}

const QList<QObject *> QUmlStartObjectBehaviorActionObject::inputs() const
{
    QList<QObject *> list;
    foreach (QUmlInputPin *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->inputs())
        list.append(element->asQObject());
    return list;
}

bool QUmlStartObjectBehaviorActionObject::isLocallyReentrant() const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->isLocallyReentrant();
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::localPostconditions() const
{
    QSet<QObject *> set;
    foreach (QUmlConstraint *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->localPostconditions())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlStartObjectBehaviorActionObject::localPreconditions() const
{
    QSet<QObject *> set;
    foreach (QUmlConstraint *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->localPreconditions())
        set.insert(element->asQObject());
    return set;
}

const QList<QObject *> QUmlStartObjectBehaviorActionObject::outputs() const
{
    QList<QObject *> list;
    foreach (QUmlOutputPin *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->outputs())
        list.append(element->asQObject());
    return list;
}

// OWNED ATTRIBUTES [InvocationAction]

const QList<QObject *> QUmlStartObjectBehaviorActionObject::arguments() const
{
    QList<QObject *> list;
    foreach (QUmlInputPin *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->arguments())
        list.append(element->asQObject());
    return list;
}

QObject *QUmlStartObjectBehaviorActionObject::onPort() const
{
    if (!qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->onPort())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->onPort()->asQObject();
}

// OWNED ATTRIBUTES [CallAction]

bool QUmlStartObjectBehaviorActionObject::isSynchronous() const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->isSynchronous();
}

const QList<QObject *> QUmlStartObjectBehaviorActionObject::results() const
{
    QList<QObject *> list;
    foreach (QUmlOutputPin *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->results())
        list.append(element->asQObject());
    return list;
}

// OWNED ATTRIBUTES [StartObjectBehaviorAction]

QObject *QUmlStartObjectBehaviorActionObject::object() const
{
    if (!qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->object())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->object()->asQObject();
}

// OPERATIONS [Element]

QSet<QObject *> QUmlStartObjectBehaviorActionObject::allOwnedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->allOwnedElements())
        set.insert(element->asQObject());
    return set;
}

bool QUmlStartObjectBehaviorActionObject::mustBeOwned() const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->mustBeOwned();
}

// OPERATIONS [NamedElement]

QList<QObject *> QUmlStartObjectBehaviorActionObject::allNamespaces() const
{
    QList<QObject *> set;
    foreach (QUmlNamespace *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->allNamespaces())
        set.append(element->asQObject());
    return set;
}

QSet<QObject *> QUmlStartObjectBehaviorActionObject::allOwningPackages() const
{
    QSet<QObject *> set;
    foreach (QUmlPackage *element, qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->allOwningPackages())
        set.insert(element->asQObject());
    return set;
}

bool QUmlStartObjectBehaviorActionObject::isDistinguishableFrom(QObject *n, QObject *ns) const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->isDistinguishableFrom(qmodelingobjectproperty_cast<QUmlNamedElement *>(n), qmodelingobjectproperty_cast<QUmlNamespace *>(ns));
}

QString QUmlStartObjectBehaviorActionObject::separator() const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->separator();
}

// OPERATIONS [RedefinableElement]

bool QUmlStartObjectBehaviorActionObject::isConsistentWith(QObject *redefinee) const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->isConsistentWith(qmodelingobjectproperty_cast<QUmlRedefinableElement *>(redefinee));
}

bool QUmlStartObjectBehaviorActionObject::isRedefinitionContextValid(QObject *redefined) const
{
    return qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->isRedefinitionContextValid(qmodelingobjectproperty_cast<QUmlRedefinableElement *>(redefined));
}

// SLOTS FOR OWNED ATTRIBUTES [Element]

void QUmlStartObjectBehaviorActionObject::addOwnedComment(QObject *ownedComment)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addOwnedComment(qmodelingobjectproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlStartObjectBehaviorActionObject::removeOwnedComment(QObject *ownedComment)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeOwnedComment(qmodelingobjectproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlStartObjectBehaviorActionObject::addOwnedElement(QObject *ownedElement)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addOwnedElement(qmodelingobjectproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlStartObjectBehaviorActionObject::removeOwnedElement(QObject *ownedElement)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeOwnedElement(qmodelingobjectproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlStartObjectBehaviorActionObject::setOwner(QObject *owner)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setOwner(qmodelingobjectproperty_cast<QUmlElement *>(owner));
}

// SLOTS FOR OWNED ATTRIBUTES [NamedElement]

void QUmlStartObjectBehaviorActionObject::addClientDependency(QObject *clientDependency)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addClientDependency(qmodelingobjectproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlStartObjectBehaviorActionObject::removeClientDependency(QObject *clientDependency)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeClientDependency(qmodelingobjectproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlStartObjectBehaviorActionObject::setName(QString name)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setName(name);
}

void QUmlStartObjectBehaviorActionObject::setNameExpression(QObject *nameExpression)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setNameExpression(qmodelingobjectproperty_cast<QUmlStringExpression *>(nameExpression));
}

void QUmlStartObjectBehaviorActionObject::setNamespace(QObject *namespace_)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setNamespace(qmodelingobjectproperty_cast<QUmlNamespace *>(namespace_));
}

void QUmlStartObjectBehaviorActionObject::setQualifiedName(QString qualifiedName)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setQualifiedName(qualifiedName);
}

void QUmlStartObjectBehaviorActionObject::setVisibility(QtUml::VisibilityKind visibility)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setVisibility(visibility);
}

// SLOTS FOR OWNED ATTRIBUTES [RedefinableElement]

void QUmlStartObjectBehaviorActionObject::setLeaf(bool isLeaf)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setLeaf(isLeaf);
}

void QUmlStartObjectBehaviorActionObject::unsetLeaf()
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->modifiedResettableProperties().removeAll(QStringLiteral("leaf"));
}

void QUmlStartObjectBehaviorActionObject::addRedefinedElement(QObject *redefinedElement)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addRedefinedElement(qmodelingobjectproperty_cast<QUmlRedefinableElement *>(redefinedElement));
}

void QUmlStartObjectBehaviorActionObject::removeRedefinedElement(QObject *redefinedElement)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeRedefinedElement(qmodelingobjectproperty_cast<QUmlRedefinableElement *>(redefinedElement));
}

void QUmlStartObjectBehaviorActionObject::addRedefinitionContext(QObject *redefinitionContext)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addRedefinitionContext(qmodelingobjectproperty_cast<QUmlClassifier *>(redefinitionContext));
}

void QUmlStartObjectBehaviorActionObject::removeRedefinitionContext(QObject *redefinitionContext)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeRedefinitionContext(qmodelingobjectproperty_cast<QUmlClassifier *>(redefinitionContext));
}

// SLOTS FOR OWNED ATTRIBUTES [ActivityNode]

void QUmlStartObjectBehaviorActionObject::setActivity(QObject *activity)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setActivity(qmodelingobjectproperty_cast<QUmlActivity *>(activity));
}

void QUmlStartObjectBehaviorActionObject::addInGroup(QObject *inGroup)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addInGroup(qmodelingobjectproperty_cast<QUmlActivityGroup *>(inGroup));
}

void QUmlStartObjectBehaviorActionObject::removeInGroup(QObject *inGroup)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeInGroup(qmodelingobjectproperty_cast<QUmlActivityGroup *>(inGroup));
}

void QUmlStartObjectBehaviorActionObject::addInInterruptibleRegion(QObject *inInterruptibleRegion)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addInInterruptibleRegion(qmodelingobjectproperty_cast<QUmlInterruptibleActivityRegion *>(inInterruptibleRegion));
}

void QUmlStartObjectBehaviorActionObject::removeInInterruptibleRegion(QObject *inInterruptibleRegion)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeInInterruptibleRegion(qmodelingobjectproperty_cast<QUmlInterruptibleActivityRegion *>(inInterruptibleRegion));
}

void QUmlStartObjectBehaviorActionObject::addInPartition(QObject *inPartition)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addInPartition(qmodelingobjectproperty_cast<QUmlActivityPartition *>(inPartition));
}

void QUmlStartObjectBehaviorActionObject::removeInPartition(QObject *inPartition)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeInPartition(qmodelingobjectproperty_cast<QUmlActivityPartition *>(inPartition));
}

void QUmlStartObjectBehaviorActionObject::setInStructuredNode(QObject *inStructuredNode)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setInStructuredNode(qmodelingobjectproperty_cast<QUmlStructuredActivityNode *>(inStructuredNode));
}

void QUmlStartObjectBehaviorActionObject::addIncoming(QObject *incoming)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addIncoming(qmodelingobjectproperty_cast<QUmlActivityEdge *>(incoming));
}

void QUmlStartObjectBehaviorActionObject::removeIncoming(QObject *incoming)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeIncoming(qmodelingobjectproperty_cast<QUmlActivityEdge *>(incoming));
}

void QUmlStartObjectBehaviorActionObject::addOutgoing(QObject *outgoing)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addOutgoing(qmodelingobjectproperty_cast<QUmlActivityEdge *>(outgoing));
}

void QUmlStartObjectBehaviorActionObject::removeOutgoing(QObject *outgoing)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeOutgoing(qmodelingobjectproperty_cast<QUmlActivityEdge *>(outgoing));
}

void QUmlStartObjectBehaviorActionObject::addRedefinedNode(QObject *redefinedNode)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addRedefinedNode(qmodelingobjectproperty_cast<QUmlActivityNode *>(redefinedNode));
}

void QUmlStartObjectBehaviorActionObject::removeRedefinedNode(QObject *redefinedNode)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeRedefinedNode(qmodelingobjectproperty_cast<QUmlActivityNode *>(redefinedNode));
}

// SLOTS FOR OWNED ATTRIBUTES [ExecutableNode]

void QUmlStartObjectBehaviorActionObject::addHandler(QObject *handler)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addHandler(qmodelingobjectproperty_cast<QUmlExceptionHandler *>(handler));
}

void QUmlStartObjectBehaviorActionObject::removeHandler(QObject *handler)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeHandler(qmodelingobjectproperty_cast<QUmlExceptionHandler *>(handler));
}

// SLOTS FOR OWNED ATTRIBUTES [Action]

void QUmlStartObjectBehaviorActionObject::setContext(QObject *context)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setContext(qmodelingobjectproperty_cast<QUmlClassifier *>(context));
}

void QUmlStartObjectBehaviorActionObject::addInput(QObject *input)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addInput(qmodelingobjectproperty_cast<QUmlInputPin *>(input));
}

void QUmlStartObjectBehaviorActionObject::removeInput(QObject *input)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeInput(qmodelingobjectproperty_cast<QUmlInputPin *>(input));
}

void QUmlStartObjectBehaviorActionObject::setLocallyReentrant(bool isLocallyReentrant)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setLocallyReentrant(isLocallyReentrant);
}

void QUmlStartObjectBehaviorActionObject::unsetLocallyReentrant()
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->modifiedResettableProperties().removeAll(QStringLiteral("locallyReentrant"));
}

void QUmlStartObjectBehaviorActionObject::addLocalPostcondition(QObject *localPostcondition)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addLocalPostcondition(qmodelingobjectproperty_cast<QUmlConstraint *>(localPostcondition));
}

void QUmlStartObjectBehaviorActionObject::removeLocalPostcondition(QObject *localPostcondition)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeLocalPostcondition(qmodelingobjectproperty_cast<QUmlConstraint *>(localPostcondition));
}

void QUmlStartObjectBehaviorActionObject::addLocalPrecondition(QObject *localPrecondition)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addLocalPrecondition(qmodelingobjectproperty_cast<QUmlConstraint *>(localPrecondition));
}

void QUmlStartObjectBehaviorActionObject::removeLocalPrecondition(QObject *localPrecondition)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeLocalPrecondition(qmodelingobjectproperty_cast<QUmlConstraint *>(localPrecondition));
}

void QUmlStartObjectBehaviorActionObject::addOutput(QObject *output)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addOutput(qmodelingobjectproperty_cast<QUmlOutputPin *>(output));
}

void QUmlStartObjectBehaviorActionObject::removeOutput(QObject *output)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeOutput(qmodelingobjectproperty_cast<QUmlOutputPin *>(output));
}

// SLOTS FOR OWNED ATTRIBUTES [InvocationAction]

void QUmlStartObjectBehaviorActionObject::addArgument(QObject *argument)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addArgument(qmodelingobjectproperty_cast<QUmlInputPin *>(argument));
}

void QUmlStartObjectBehaviorActionObject::removeArgument(QObject *argument)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeArgument(qmodelingobjectproperty_cast<QUmlInputPin *>(argument));
}

void QUmlStartObjectBehaviorActionObject::setOnPort(QObject *onPort)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setOnPort(qmodelingobjectproperty_cast<QUmlPort *>(onPort));
}

// SLOTS FOR OWNED ATTRIBUTES [CallAction]

void QUmlStartObjectBehaviorActionObject::setSynchronous(bool isSynchronous)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setSynchronous(isSynchronous);
}

void QUmlStartObjectBehaviorActionObject::unsetSynchronous()
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->modifiedResettableProperties().removeAll(QStringLiteral("synchronous"));
}

void QUmlStartObjectBehaviorActionObject::addResult(QObject *result)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->addResult(qmodelingobjectproperty_cast<QUmlOutputPin *>(result));
}

void QUmlStartObjectBehaviorActionObject::removeResult(QObject *result)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->removeResult(qmodelingobjectproperty_cast<QUmlOutputPin *>(result));
}

// SLOTS FOR OWNED ATTRIBUTES [StartObjectBehaviorAction]

void QUmlStartObjectBehaviorActionObject::setObject(QObject *object)
{
    qmodelingobjectproperty_cast<QUmlStartObjectBehaviorAction *>(this)->setObject(qmodelingobjectproperty_cast<QUmlInputPin *>(object));
}

QT_END_NAMESPACE

