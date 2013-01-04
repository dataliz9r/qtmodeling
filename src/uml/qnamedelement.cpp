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

#include "qnamedelement.h"
#include "qnamedelement_p.h"

#include "qnamespace_p.h"

#include <QtUml/QPackage>
#include <QtUml/QNamespace>
#include <QtUml/QDependency>
#include <QtUml/QStringExpression>

#include <QtWrappedObjects/QtWrappedObjectsEnumerations>

QT_BEGIN_NAMESPACE_QTUML

QNamedElementPrivate::QNamedElementPrivate() :
    nameExpression(0),
    namespace_(0)
{
}

QNamedElementPrivate::~QNamedElementPrivate()
{
}

void QNamedElementPrivate::setNamespace_(QNamespace *namespace_)
{
    // This is a read-only derived-union association end

    if (this->namespace_ != namespace_) {
        Q_Q(QNamedElement);
        // Adjust opposite property
        if (this->namespace_)
            (qwrappedobject_cast<QNamespacePrivate *>(this->namespace_->d_func()))->removeOwnedMember(q);

        this->namespace_ = namespace_;

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(this))->setOwner(qwrappedobject_cast<QElement *>(namespace_));

        // Adjust opposite property
        if (namespace_)
            (qwrappedobject_cast<QNamespacePrivate *>(namespace_->d_func()))->addOwnedMember(q);
    }
}

/*!
    \class QNamedElement

    \inmodule QtUml

    \brief A named element supports using a string expression to specify its name. This allows names of model elements to involve template parameters. The actual name is evaluated from the string expression only when it is sensible to do so (e.g., when a template is bound).A named element is an element in a model that may have a name.
 */

QNamedElement::QNamedElement(QWrappedObject *wrapper, QWrappedObject *parent) :
    QElement(*new QNamedElementPrivate, wrapper, parent)
{
    setPropertyData();
}

QNamedElement::QNamedElement(QNamedElementPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QElement(dd, wrapper, parent)
{
    setPropertyData();
}

QNamedElement::~QNamedElement()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QNamedElement::name() const
{
    // This is a read-write attribute

    Q_D(const QNamedElement);
    return d->name;
}

void QNamedElement::setName(QString name)
{
    // This is a read-write attribute

    Q_D(QNamedElement);
    if (d->name != name) {
        d->name = name;
        QWrappedObject *wrappedObject = this;
        while (wrappedObject->wrapper())
            wrappedObject = wrappedObject->wrapper();
        wrappedObject->setObjectName(name);
    }
}

/*!
    Determines where the NamedElement appears within different Namespaces within the overall model, and its accessibility.
 */
QtUml::VisibilityKind QNamedElement::visibility() const
{
    // This is a read-write attribute

    Q_D(const QNamedElement);
    return d->visibility;
}

void QNamedElement::setVisibility(QtUml::VisibilityKind visibility)
{
    // This is a read-write attribute

    Q_D(QNamedElement);
    if (d->visibility != visibility) {
        d->visibility = visibility;
    }
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QNamedElement::qualifiedName() const
{
    // This is a read-only derived attribute

    Q_D(const QNamedElement);
    if (d->name.isEmpty()) return QString();
    QString qualifiedName_(d->name);
    QList<QNamespace *> allNamespaces_ = allNamespaces();
    QString separator_ = separator();
    foreach (QNamespace *namespace_, allNamespaces_) {
        if (namespace_->name().isEmpty())
            return QString();
        qualifiedName_.prepend(separator_).prepend(namespace_->name());
    }
    return qualifiedName_;
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QNamedElement::nameExpression() const
{
    // This is a read-write association end

    Q_D(const QNamedElement);
    return d->nameExpression;
}

void QNamedElement::setNameExpression(QStringExpression *nameExpression)
{
    // This is a read-write association end

    Q_D(QNamedElement);
    if (d->nameExpression != nameExpression) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(d->nameExpression));

        d->nameExpression = nameExpression;

        // Adjust subsetted property(ies)
        if (nameExpression) {
            (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(nameExpression));
        }
    }
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QNamedElement::namespace_() const
{
    // This is a read-only derived-union association end

    Q_D(const QNamedElement);
    return d->namespace_;
}

/*!
    Indicates the dependencies that reference the client.
 */
QSet<QDependency *> QNamedElement::clientDependencies() const
{
    // This is a read-write association end

    Q_D(const QNamedElement);
    return d->clientDependencies;
}

void QNamedElement::addClientDependency(QDependency *clientDependency)
{
    // This is a read-write association end

    Q_D(QNamedElement);
    if (!d->clientDependencies.contains(clientDependency)) {
        d->clientDependencies.insert(clientDependency);

        // Adjust opposite property
        clientDependency->addClient(this);
    }
}

void QNamedElement::removeClientDependency(QDependency *clientDependency)
{
    // This is a read-write association end

    Q_D(QNamedElement);
    if (d->clientDependencies.contains(clientDependency)) {
        d->clientDependencies.remove(clientDependency);

        // Adjust opposite property
        if (clientDependency)
            clientDependency->removeClient(this);
    }
}

/*!
    The query allNamespaces() gives the sequence of namespaces in which the NamedElement is nested, working outwards.
 */
QList<QNamespace *> QNamedElement::allNamespaces() const
{
    Q_D(const QNamedElement);
    if (!d->namespace_) {
        return QList<QNamespace *>();
    }
    else {
        QList<QNamespace *> allNamespaces_;
        QNamespace *namespace_ = this->namespace_();
        while (namespace_) {
            allNamespaces_.append(namespace_);
            namespace_ = namespace_->namespace_();
        }
        return allNamespaces_;
    }
}

/*!
    The query allOwningPackages() returns all the directly or indirectly owning packages.
 */
QSet<QPackage *> QNamedElement::allOwningPackages() const
{
    qWarning("QNamedElement::allOwningPackages: operation to be implemented");

    return QSet<QPackage *>(); // change here to your derived return
}

/*!
    The query isDistinguishableFrom() determines whether two NamedElements may logically co-exist within a Namespace. By default, two named elements are distinguishable if (a) they have unrelated types or (b) they have related types but different names.
 */
bool QNamedElement::isDistinguishableFrom(const QNamedElement *n, const QNamespace *ns) const
{
    qWarning("QNamedElement::isDistinguishableFrom: operation to be implemented");
    Q_UNUSED(n);
    Q_UNUSED(ns);

    return bool(); // change here to your derived return
}

/*!
    The query separator() gives the string that is used to separate names when constructing a qualified name.
 */
QString QNamedElement::separator() const
{
    return QStringLiteral("::");
}

void QNamedElement::registerMetaTypes() const
{
    qRegisterMetaType<QPackage *>("QPackage *");
    qRegisterMetaType<QSet<QPackage *>>("QSet<QPackage *>");
    qRegisterMetaType<QList<QPackage *>>("QList<QPackage *>");

    qRegisterMetaType<QNamespace *>("QNamespace *");
    qRegisterMetaType<QSet<QNamespace *>>("QSet<QNamespace *>");
    qRegisterMetaType<QList<QNamespace *>>("QList<QNamespace *>");

    qRegisterMetaType<QDependency *>("QDependency *");
    qRegisterMetaType<QSet<QDependency *>>("QSet<QDependency *>");
    qRegisterMetaType<QList<QDependency *>>("QList<QDependency *>");

    qRegisterMetaType<QStringExpression *>("QStringExpression *");
    qRegisterMetaType<QSet<QStringExpression *>>("QSet<QStringExpression *>");
    qRegisterMetaType<QList<QStringExpression *>>("QList<QStringExpression *>");

    QElement::registerMetaTypes();

    foreach (QWrappedObject *wrappedObject, wrappedObjects())
        wrappedObject->registerMetaTypes();
}

void QNamedElement::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("name")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("name")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("name")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The name of the NamedElement.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("name")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("name")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("name")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("visibility")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("visibility")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("visibility")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Determines where the NamedElement appears within different Namespaces within the overall model, and its accessibility.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("visibility")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("visibility")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("visibility")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("qualifiedName")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("qualifiedName")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("qualifiedName")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("qualifiedName")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("qualifiedName")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("qualifiedName")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("nameExpression")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("nameExpression")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("nameExpression")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The string expression used to define the name of this named element.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("nameExpression")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("nameExpression")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QElement::ownedElements");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("nameExpression")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("namespace_")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("namespace_")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = true;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("namespace_")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Specifies the namespace that owns the NamedElement.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("namespace_")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("namespace_")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QElement::owner");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("namespace_")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QNamespace::ownedMember");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("clientDependencies")][QtWrappedObjects::QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("clientDependencies")][QtWrappedObjects::QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("clientDependencies")][QtWrappedObjects::QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Indicates the dependencies that reference the client.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("clientDependencies")][QtWrappedObjects::QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("clientDependencies")][QtWrappedObjects::QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QNamedElement")][QString::fromLatin1("clientDependencies")][QtWrappedObjects::QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QDependency::client");

    QElement::setPropertyData();
}

#include "moc_qnamedelement.cpp"

QT_END_NAMESPACE_QTUML

