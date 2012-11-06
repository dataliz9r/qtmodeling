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

#include "qparameter.h"
#include "qparameter_p.h"

#include <QtUml/QValueSpecification>
#include <QtUml/QOperation>
#include <QtUml/QParameterSet>

QT_BEGIN_NAMESPACE_QTUML

QParameterPrivate::QParameterPrivate() :
    isException(false),
    direction(QtUml::ParameterDirectionIn),
    isStream(false),
    operation(0),
    defaultValue(0),
    parameterSets(new QSet<QParameterSet *>)
{
}

QParameterPrivate::~QParameterPrivate()
{
    delete parameterSets;
}

/*!
    \class QParameter

    \inmodule QtUml

    \brief Parameters are allowed to be treated as connectable elements.A parameter is a specification of an argument used to pass information into or out of an invocation of a behavioral feature.Parameters have support for streaming, exceptions, and parameter sets.
 */

QParameter::QParameter(QObject *parent) :
    QObject(*new QParameterPrivate, parent),
    _wrappedMultiplicityElement(new QMultiplicityElement(this)),
    _wrappedConnectableElement(new QConnectableElement(this))
{
    qRegisterMetaType<QParameter *>("QParameter *");
    qRegisterMetaType<const QSet<QParameter *> *>("const QSet<QParameter *> *");
    qRegisterMetaType<const QList<QParameter *> *>("const QList<QParameter *> *");
}

QParameter::QParameter(QParameterPrivate &dd, QObject *parent) :
    QObject(dd, parent),
    _wrappedMultiplicityElement(new QMultiplicityElement(this)),
    _wrappedConnectableElement(new QConnectableElement(this))
{
    qRegisterMetaType<QParameter *>("QParameter *");
    qRegisterMetaType<const QSet<QParameter *> *>("const QSet<QParameter *> *");
    qRegisterMetaType<const QList<QParameter *> *>("const QList<QParameter *> *");
}

QParameter::~QParameter()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QParameter::ownedElements() const
{
    return (qtuml_object_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QParameter::owner() const
{
    return (qtuml_object_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QParameter::ownedComments() const
{
    return (qtuml_object_cast<const QElement *>(this))->ownedComments();
}

void QParameter::addOwnedComment(QComment *ownedComment)
{
    (qtuml_object_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QParameter::removeOwnedComment(QComment *ownedComment)
{
    (qtuml_object_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QMultiplicityElement
// ---------------------------------------------------------------

/*!
    Specifies the upper bound of the multiplicity interval.
 */
qint32 QParameter::upper() const
{
    return (qtuml_object_cast<const QMultiplicityElement *>(this))->upper();
}

void QParameter::setUpper(qint32 upper)
{
    (qtuml_object_cast<QMultiplicityElement *>(this))->setUpper(upper);
}

/*!
    For a multivalued multiplicity, this attributes specifies whether the values in an instantiation of this element are unique.
 */
bool QParameter::isUnique() const
{
    return (qtuml_object_cast<const QMultiplicityElement *>(this))->isUnique();
}

void QParameter::setUnique(bool isUnique)
{
    (qtuml_object_cast<QMultiplicityElement *>(this))->setUnique(isUnique);
}

/*!
    For a multivalued multiplicity, this attribute specifies whether the values in an instantiation of this element are sequentially ordered.
 */
bool QParameter::isOrdered() const
{
    return (qtuml_object_cast<const QMultiplicityElement *>(this))->isOrdered();
}

void QParameter::setOrdered(bool isOrdered)
{
    (qtuml_object_cast<QMultiplicityElement *>(this))->setOrdered(isOrdered);
}

/*!
    Specifies the lower bound of the multiplicity interval.
 */
qint32 QParameter::lower() const
{
    return (qtuml_object_cast<const QMultiplicityElement *>(this))->lower();
}

void QParameter::setLower(qint32 lower)
{
    (qtuml_object_cast<QMultiplicityElement *>(this))->setLower(lower);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QMultiplicityElement
// ---------------------------------------------------------------

/*!
    The specification of the upper bound for this multiplicity.
 */
QValueSpecification *QParameter::upperValue() const
{
    return (qtuml_object_cast<const QMultiplicityElement *>(this))->upperValue();
}

void QParameter::setUpperValue(QValueSpecification *upperValue)
{
    (qtuml_object_cast<QMultiplicityElement *>(this))->setUpperValue(upperValue);
}

/*!
    The specification of the lower bound for this multiplicity.
 */
QValueSpecification *QParameter::lowerValue() const
{
    return (qtuml_object_cast<const QMultiplicityElement *>(this))->lowerValue();
}

void QParameter::setLowerValue(QValueSpecification *lowerValue)
{
    (qtuml_object_cast<QMultiplicityElement *>(this))->setLowerValue(lowerValue);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QParameter::name() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->name();
}

void QParameter::setName(QString name)
{
    (qtuml_object_cast<QNamedElement *>(this))->setName(name);
}

/*!
    Determines where the NamedElement appears within different Namespaces within the overall model, and its accessibility.
 */
QtUml::VisibilityKind QParameter::visibility() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->visibility();
}

void QParameter::setVisibility(QtUml::VisibilityKind visibility)
{
    (qtuml_object_cast<QNamedElement *>(this))->setVisibility(visibility);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QParameter::qualifiedName() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QParameter::nameExpression() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->nameExpression();
}

void QParameter::setNameExpression(QStringExpression *nameExpression)
{
    (qtuml_object_cast<QNamedElement *>(this))->setNameExpression(nameExpression);
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QParameter::namespace_() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->namespace_();
}

/*!
    Indicates the dependencies that reference the client.
 */
const QSet<QDependency *> *QParameter::clientDependencies() const
{
    return (qtuml_object_cast<const QNamedElement *>(this))->clientDependencies();
}

void QParameter::addClientDependency(QDependency *clientDependency)
{
    (qtuml_object_cast<QNamedElement *>(this))->addClientDependency(clientDependency);
}

void QParameter::removeClientDependency(QDependency *clientDependency)
{
    (qtuml_object_cast<QNamedElement *>(this))->removeClientDependency(clientDependency);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QTypedElement
// ---------------------------------------------------------------

/*!
    This information is derived from the return result for this Operation.The type of the TypedElement.
 */
QType *QParameter::type() const
{
    return (qtuml_object_cast<const QTypedElement *>(this))->type();
}

void QParameter::setType(QType *type)
{
    (qtuml_object_cast<QTypedElement *>(this))->setType(type);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QParameterableElement
// ---------------------------------------------------------------

/*!
    The formal template parameter that owns this element.
 */
QTemplateParameter *QParameter::owningTemplateParameter() const
{
    return (qtuml_object_cast<const QParameterableElement *>(this))->owningTemplateParameter();
}

void QParameter::setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter)
{
    (qtuml_object_cast<QParameterableElement *>(this))->setOwningTemplateParameter(owningTemplateParameter);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QConnectableElement
// ---------------------------------------------------------------

/*!
    Denotes a set of connector ends that attaches to this connectable element.
 */
const QList<QConnectorEnd *> *QParameter::ends() const
{
    return (qtuml_object_cast<const QConnectableElement *>(this))->ends();
}

/*!
    The ConnectableElementTemplateParameter for this ConnectableElement parameter.
 */
QConnectableElementTemplateParameter *QParameter::templateParameter() const
{
    return (qtuml_object_cast<const QConnectableElement *>(this))->templateParameter();
}

void QParameter::setTemplateParameter(QConnectableElementTemplateParameter *templateParameter)
{
    (qtuml_object_cast<QConnectableElement *>(this))->setTemplateParameter(templateParameter);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QParameter
// ---------------------------------------------------------------

/*!
    Tells whether an output parameter may emit a value to the exclusion of the other outputs.
 */
bool QParameter::isException() const
{
    // This is a read-write attribute

    Q_D(const QParameter);
    return d->isException;
}

void QParameter::setException(bool isException)
{
    // This is a read-write attribute

    Q_D(QParameter);
    if (d->isException != isException) {
        d->isException = isException;
    }
}

/*!
    Specifies a String that represents a value to be used when no argument is supplied for the Parameter.
 */
QString QParameter::default_() const
{
    // This is a read-write derived attribute

    qWarning("QParameter::default_: to be implemented (this is a derived attribute)");

    return QString(); // change here to your derived return
}

void QParameter::setDefault_(QString default_)
{
    // This is a read-write derived attribute

    qWarning("QParameter::setDefault_: to be implemented (this is a derived attribute)");
    Q_UNUSED(default_);

    if (false) { // change to your derived change criteria
        // change to your derived code
    }
}

/*!
    Indicates whether a parameter is being sent into or out of a behavioral element.
 */
QtUml::ParameterDirectionKind QParameter::direction() const
{
    // This is a read-write attribute

    Q_D(const QParameter);
    return d->direction;
}

void QParameter::setDirection(QtUml::ParameterDirectionKind direction)
{
    // This is a read-write attribute

    Q_D(QParameter);
    if (d->direction != direction) {
        d->direction = direction;
    }
}

/*!
    Tells whether an input parameter may accept values while its behavior is executing, or whether an output parameter post values while the behavior is executing.
 */
bool QParameter::isStream() const
{
    // This is a read-write attribute

    Q_D(const QParameter);
    return d->isStream;
}

void QParameter::setStream(bool isStream)
{
    // This is a read-write attribute

    Q_D(QParameter);
    if (d->isStream != isStream) {
        d->isStream = isStream;
    }
}

/*!
    Specifies the effect that the owner of the parameter has on values passed in or out of the parameter.
 */
QtUml::ParameterEffectKind QParameter::effect() const
{
    // This is a read-write attribute

    Q_D(const QParameter);
    return d->effect;
}

void QParameter::setEffect(QtUml::ParameterEffectKind effect)
{
    // This is a read-write attribute

    Q_D(QParameter);
    if (d->effect != effect) {
        d->effect = effect;
    }
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QParameter
// ---------------------------------------------------------------

/*!
    References the Operation owning this parameter.
 */
QOperation *QParameter::operation() const
{
    // This is a read-write association end

    Q_D(const QParameter);
    return d->operation;
}

void QParameter::setOperation(QOperation *operation)
{
    // This is a read-write association end

    Q_D(QParameter);
    if (d->operation != operation) {
        // Adjust opposite property
        if (d->operation)
            d->operation->removeOwnedParameter(this);

        d->operation = operation;

        // Adjust subsetted property(ies)
        (qtuml_object_cast<QNamedElementPrivate *>(d))->setNamespace_(qtuml_object_cast<QNamespace *>(operation));

        // Adjust opposite property
        if (operation)
            operation->addOwnedParameter(this);
    }
}

/*!
    Specifies a ValueSpecification that represents a value to be used when no argument is supplied for the Parameter.
 */
QValueSpecification *QParameter::defaultValue() const
{
    // This is a read-write association end

    Q_D(const QParameter);
    return d->defaultValue;
}

void QParameter::setDefaultValue(QValueSpecification *defaultValue)
{
    // This is a read-write association end

    Q_D(QParameter);
    if (d->defaultValue != defaultValue) {
        // Adjust subsetted property(ies)
        (qtuml_object_cast<QElementPrivate *>(d))->removeOwnedElement(qtuml_object_cast<QElement *>(d->defaultValue));

        d->defaultValue = defaultValue;

        // Adjust subsetted property(ies)
        if (defaultValue) {
            (qtuml_object_cast<QElementPrivate *>(d))->addOwnedElement(qtuml_object_cast<QElement *>(defaultValue));
        }
    }
}

/*!
    The parameter sets containing the parameter. See ParameterSet.
 */
const QSet<QParameterSet *> *QParameter::parameterSets() const
{
    // This is a read-write association end

    Q_D(const QParameter);
    return d->parameterSets;
}

void QParameter::addParameterSet(QParameterSet *parameterSet)
{
    // This is a read-write association end

    Q_D(QParameter);
    if (!d->parameterSets->contains(parameterSet)) {
        d->parameterSets->insert(parameterSet);

        // Adjust opposite property
        parameterSet->addParameter(this);
    }
}

void QParameter::removeParameterSet(QParameterSet *parameterSet)
{
    // This is a read-write association end

    Q_D(QParameter);
    if (d->parameterSets->contains(parameterSet)) {
        d->parameterSets->remove(parameterSet);

        // Adjust opposite property
        if (parameterSet)
            parameterSet->removeParameter(this);
    }
}

#include "moc_qparameter.cpp"

QT_END_NAMESPACE_QTUML

