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
#include "qumlenumeration.h"

#include "private/qumlenumerationobject_p.h"

#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlClassifierTemplateParameter>
#include <QtUml/QUmlCollaborationUse>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlElementImport>
#include <QtUml/QUmlEnumerationLiteral>
#include <QtUml/QUmlFeature>
#include <QtUml/QUmlGeneralization>
#include <QtUml/QUmlGeneralizationSet>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOperation>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlPackageImport>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlProperty>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlRedefinableTemplateSignature>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlSubstitution>
#include <QtUml/QUmlTemplateBinding>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlTemplateSignature>
#include <QtUml/QUmlType>
#include <QtUml/QUmlUseCase>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlEnumeration

    \inmodule QtUml

    \brief An enumeration is a data type whose values are enumerated in the model as enumeration literals.
 */

/*!
    Creates a new QUmlEnumeration. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlEnumeration::QUmlEnumeration(bool createQModelingObject) :
    QUmlDataType(false)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlEnumerationObject(this));
}

/*!
    Destroys the QUmlEnumeration.
 */
QUmlEnumeration::~QUmlEnumeration()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlEnumeration.
*/
QModelingElement *QUmlEnumeration::clone() const
{
    QUmlEnumeration *c = new QUmlEnumeration;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    foreach (QUmlElementImport *element, elementImports())
        c->addElementImport(dynamic_cast<QUmlElementImport *>(element->clone()));
    foreach (QUmlConstraint *element, ownedRules())
        c->addOwnedRule(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlPackageImport *element, packageImports())
        c->addPackageImport(dynamic_cast<QUmlPackageImport *>(element->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    foreach (QUmlTemplateBinding *element, templateBindings())
        c->addTemplateBinding(dynamic_cast<QUmlTemplateBinding *>(element->clone()));
    foreach (QUmlCollaborationUse *element, collaborationUses())
        c->addCollaborationUse(dynamic_cast<QUmlCollaborationUse *>(element->clone()));
    foreach (QUmlGeneralization *element, generalizations())
        c->addGeneralization(dynamic_cast<QUmlGeneralization *>(element->clone()));
    c->setAbstract(isAbstract());
    c->setFinalSpecialization(isFinalSpecialization());
    if (ownedTemplateSignature())
        c->setOwnedTemplateSignature(dynamic_cast<QUmlRedefinableTemplateSignature *>(ownedTemplateSignature()->clone()));
    foreach (QUmlUseCase *element, ownedUseCases())
        c->addOwnedUseCase(dynamic_cast<QUmlUseCase *>(element->clone()));
    foreach (QUmlSubstitution *element, substitutions())
        c->addSubstitution(dynamic_cast<QUmlSubstitution *>(element->clone()));
    foreach (QUmlProperty *element, ownedAttributes())
        c->addOwnedAttribute(dynamic_cast<QUmlProperty *>(element->clone()));
    foreach (QUmlOperation *element, ownedOperations())
        c->addOwnedOperation(dynamic_cast<QUmlOperation *>(element->clone()));
    foreach (QUmlEnumerationLiteral *element, ownedLiterals())
        c->addOwnedLiteral(dynamic_cast<QUmlEnumerationLiteral *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The ordered set of literals for this Enumeration.

    \sa addOwnedLiteral(), removeOwnedLiteral()

    \b {Subsetted property(ies):} QUmlNamespace::ownedMembers().

    \b {Opposite property(ies):} QUmlEnumerationLiteral::enumeration().
 */
const QList<QUmlEnumerationLiteral *> QUmlEnumeration::ownedLiterals() const
{
    // This is a read-write association end

    return _ownedLiterals;
}

/*!
    Adds \a ownedLiteral to ownedLiterals.

    \sa ownedLiterals(), removeOwnedLiteral()
 */
void QUmlEnumeration::addOwnedLiteral(QUmlEnumerationLiteral *ownedLiteral)
{
    // This is a read-write association end

    if (!_ownedLiterals.contains(ownedLiteral)) {
        _ownedLiterals.append(ownedLiteral);
        if (ownedLiteral && ownedLiteral->asQModelingObject() && this->asQModelingObject())
            QObject::connect(ownedLiteral->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeOwnedLiteral(QObject *)));
        ownedLiteral->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedMember(ownedLiteral);

        // Adjust opposite properties
        if (ownedLiteral) {
            ownedLiteral->setEnumeration(this);
        }
    }
}

/*!
    Removes \a ownedLiteral from ownedLiterals.

    \sa ownedLiterals(), addOwnedLiteral()
 */
void QUmlEnumeration::removeOwnedLiteral(QUmlEnumerationLiteral *ownedLiteral)
{
    // This is a read-write association end

    if (_ownedLiterals.contains(ownedLiteral)) {
        _ownedLiterals.removeAll(ownedLiteral);
        if (ownedLiteral->asQModelingObject())
            ownedLiteral->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(ownedLiteral);

        // Adjust opposite properties
        if (ownedLiteral) {
            ownedLiteral->setEnumeration(0);
        }
    }
}

QT_END_NAMESPACE

