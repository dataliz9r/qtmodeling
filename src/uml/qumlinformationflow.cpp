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
#include "qumlinformationflow.h"

#include "private/qumlinformationflowobject_p.h"

#include <QtUml/QUmlActivityEdge>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConnector>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlMessage>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlRelationship>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>

/*!
    \class QUmlInformationFlow

    \inmodule QtUml

    \brief An information flow specifies that one or more information items circulates from its sources to its targets. Information flows require some kind of information channel for transmitting information items from the source to the destination. An information channel is represented in various ways depending on the nature of its sources and targets. It may be represented by connectors, links, associations, or even dependencies. For example, if the source and destination are parts in some composite structure such as a collaboration, then the information channel is likely to be represented by a connector between them. Or, if the source and target are objects (which are a kind of instance specification), they may be represented by a link that joins the two, and so on.
 */
QUmlInformationFlow::QUmlInformationFlow(bool createQObject)
{
    if (createQObject)
        _qObject = new QUmlInformationFlowObject(this);
    setPropertyData();
}

QUmlInformationFlow::~QUmlInformationFlow()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlInformationFlow::clone() const
{
    QUmlInformationFlow *c = new QUmlInformationFlow;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    if (owningTemplateParameter())
        c->setOwningTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(owningTemplateParameter()->clone()));
    if (templateParameter())
        c->setTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(templateParameter()->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    foreach (QUmlClassifier *element, conveyed())
        c->addConveyed(dynamic_cast<QUmlClassifier *>(element->clone()));
    foreach (QUmlNamedElement *element, informationSources())
        c->addInformationSource(dynamic_cast<QUmlNamedElement *>(element->clone()));
    foreach (QUmlNamedElement *element, informationTargets())
        c->addInformationTarget(dynamic_cast<QUmlNamedElement *>(element->clone()));
    foreach (QUmlRelationship *element, realizations())
        c->addRealization(dynamic_cast<QUmlRelationship *>(element->clone()));
    foreach (QUmlActivityEdge *element, realizingActivityEdges())
        c->addRealizingActivityEdge(dynamic_cast<QUmlActivityEdge *>(element->clone()));
    foreach (QUmlConnector *element, realizingConnectors())
        c->addRealizingConnector(dynamic_cast<QUmlConnector *>(element->clone()));
    foreach (QUmlMessage *element, realizingMessages())
        c->addRealizingMessage(dynamic_cast<QUmlMessage *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Specifies the information items that may circulate on this information flow.
 */
const QSet<QUmlClassifier *> QUmlInformationFlow::conveyed() const
{
    // This is a read-write association end

    return _conveyed;
}

void QUmlInformationFlow::addConveyed(QUmlClassifier *conveyed)
{
    // This is a read-write association end

    if (!_conveyed.contains(conveyed)) {
        _conveyed.insert(conveyed);
        if (conveyed && conveyed->asQObject() && this->asQObject())
            QObject::connect(conveyed->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeConveyed(QObject *)));
    }
}

void QUmlInformationFlow::removeConveyed(QUmlClassifier *conveyed)
{
    // This is a read-write association end

    if (_conveyed.contains(conveyed)) {
        _conveyed.remove(conveyed);
    }
}

/*!
    Defines from which source the conveyed InformationItems are initiated.
 */
const QSet<QUmlNamedElement *> QUmlInformationFlow::informationSources() const
{
    // This is a read-write association end

    return _informationSources;
}

void QUmlInformationFlow::addInformationSource(QUmlNamedElement *informationSource)
{
    // This is a read-write association end

    if (!_informationSources.contains(informationSource)) {
        _informationSources.insert(informationSource);
        if (informationSource && informationSource->asQObject() && this->asQObject())
            QObject::connect(informationSource->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeInformationSource(QObject *)));

        // Adjust subsetted properties
        addSource(informationSource);
    }
}

void QUmlInformationFlow::removeInformationSource(QUmlNamedElement *informationSource)
{
    // This is a read-write association end

    if (_informationSources.contains(informationSource)) {
        _informationSources.remove(informationSource);

        // Adjust subsetted properties
        removeSource(informationSource);
    }
}

/*!
    Defines to which target the conveyed InformationItems are directed.
 */
const QSet<QUmlNamedElement *> QUmlInformationFlow::informationTargets() const
{
    // This is a read-write association end

    return _informationTargets;
}

void QUmlInformationFlow::addInformationTarget(QUmlNamedElement *informationTarget)
{
    // This is a read-write association end

    if (!_informationTargets.contains(informationTarget)) {
        _informationTargets.insert(informationTarget);
        if (informationTarget && informationTarget->asQObject() && this->asQObject())
            QObject::connect(informationTarget->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeInformationTarget(QObject *)));

        // Adjust subsetted properties
        addTarget(informationTarget);
    }
}

void QUmlInformationFlow::removeInformationTarget(QUmlNamedElement *informationTarget)
{
    // This is a read-write association end

    if (_informationTargets.contains(informationTarget)) {
        _informationTargets.remove(informationTarget);

        // Adjust subsetted properties
        removeTarget(informationTarget);
    }
}

/*!
    Determines which Relationship will realize the specified flow
 */
const QSet<QUmlRelationship *> QUmlInformationFlow::realizations() const
{
    // This is a read-write association end

    return _realizations;
}

void QUmlInformationFlow::addRealization(QUmlRelationship *realization)
{
    // This is a read-write association end

    if (!_realizations.contains(realization)) {
        _realizations.insert(realization);
        if (realization && realization->asQObject() && this->asQObject())
            QObject::connect(realization->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeRealization(QObject *)));
    }
}

void QUmlInformationFlow::removeRealization(QUmlRelationship *realization)
{
    // This is a read-write association end

    if (_realizations.contains(realization)) {
        _realizations.remove(realization);
    }
}

/*!
    Determines which ActivityEdges will realize the specified flow.
 */
const QSet<QUmlActivityEdge *> QUmlInformationFlow::realizingActivityEdges() const
{
    // This is a read-write association end

    return _realizingActivityEdges;
}

void QUmlInformationFlow::addRealizingActivityEdge(QUmlActivityEdge *realizingActivityEdge)
{
    // This is a read-write association end

    if (!_realizingActivityEdges.contains(realizingActivityEdge)) {
        _realizingActivityEdges.insert(realizingActivityEdge);
        if (realizingActivityEdge && realizingActivityEdge->asQObject() && this->asQObject())
            QObject::connect(realizingActivityEdge->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeRealizingActivityEdge(QObject *)));
    }
}

void QUmlInformationFlow::removeRealizingActivityEdge(QUmlActivityEdge *realizingActivityEdge)
{
    // This is a read-write association end

    if (_realizingActivityEdges.contains(realizingActivityEdge)) {
        _realizingActivityEdges.remove(realizingActivityEdge);
    }
}

/*!
    Determines which Connectors will realize the specified flow.
 */
const QSet<QUmlConnector *> QUmlInformationFlow::realizingConnectors() const
{
    // This is a read-write association end

    return _realizingConnectors;
}

void QUmlInformationFlow::addRealizingConnector(QUmlConnector *realizingConnector)
{
    // This is a read-write association end

    if (!_realizingConnectors.contains(realizingConnector)) {
        _realizingConnectors.insert(realizingConnector);
        if (realizingConnector && realizingConnector->asQObject() && this->asQObject())
            QObject::connect(realizingConnector->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeRealizingConnector(QObject *)));
    }
}

void QUmlInformationFlow::removeRealizingConnector(QUmlConnector *realizingConnector)
{
    // This is a read-write association end

    if (_realizingConnectors.contains(realizingConnector)) {
        _realizingConnectors.remove(realizingConnector);
    }
}

/*!
    Determines which Messages will realize the specified flow.
 */
const QSet<QUmlMessage *> QUmlInformationFlow::realizingMessages() const
{
    // This is a read-write association end

    return _realizingMessages;
}

void QUmlInformationFlow::addRealizingMessage(QUmlMessage *realizingMessage)
{
    // This is a read-write association end

    if (!_realizingMessages.contains(realizingMessage)) {
        _realizingMessages.insert(realizingMessage);
        if (realizingMessage && realizingMessage->asQObject() && this->asQObject())
            QObject::connect(realizingMessage->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeRealizingMessage(QObject *)));
    }
}

void QUmlInformationFlow::removeRealizingMessage(QUmlMessage *realizingMessage)
{
    // This is a read-write association end

    if (_realizingMessages.contains(realizingMessage)) {
        _realizingMessages.remove(realizingMessage);
    }
}

void QUmlInformationFlow::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("conveyed")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("conveyed")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlInformationFlow");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("conveyed")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("conveyed")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("conveyed")][QtModeling::DocumentationRole] = QStringLiteral("Specifies the information items that may circulate on this information flow.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("conveyed")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("conveyed")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("conveyed")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationSource")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationSource")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlInformationFlow");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationSource")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationSource")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationSource")][QtModeling::DocumentationRole] = QStringLiteral("Defines from which source the conveyed InformationItems are initiated.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationSource")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationSource")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("DirectedRelationship-source");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationSource")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationTarget")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationTarget")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlInformationFlow");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationTarget")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationTarget")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationTarget")][QtModeling::DocumentationRole] = QStringLiteral("Defines to which target the conveyed InformationItems are directed.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationTarget")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationTarget")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("DirectedRelationship-target");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("informationTarget")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realization")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realization")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlInformationFlow");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realization")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realization")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realization")][QtModeling::DocumentationRole] = QStringLiteral("Determines which Relationship will realize the specified flow");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realization")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realization")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realization")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingActivityEdge")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingActivityEdge")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlInformationFlow");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingActivityEdge")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingActivityEdge")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingActivityEdge")][QtModeling::DocumentationRole] = QStringLiteral("Determines which ActivityEdges will realize the specified flow.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingActivityEdge")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingActivityEdge")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingActivityEdge")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingConnector")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingConnector")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlInformationFlow");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingConnector")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingConnector")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingConnector")][QtModeling::DocumentationRole] = QStringLiteral("Determines which Connectors will realize the specified flow.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingConnector")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingConnector")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingConnector")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingMessage")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingMessage")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlInformationFlow");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingMessage")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingMessage")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingMessage")][QtModeling::DocumentationRole] = QStringLiteral("Determines which Messages will realize the specified flow.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingMessage")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingMessage")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInformationFlow")][QStringLiteral("realizingMessage")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

