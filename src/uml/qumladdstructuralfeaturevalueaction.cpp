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
#include "qumladdstructuralfeaturevalueaction.h"

#include "private/qumladdstructuralfeaturevalueactionobject_p.h"

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
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuralFeature>
#include <QtUml/QUmlStructuredActivityNode>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlAddStructuralFeatureValueAction

    \inmodule QtUml

    \brief An add structural feature value action is a write structural feature action for adding values to a structural feature.
 */

/*!
    Creates a new QUmlAddStructuralFeatureValueAction. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlAddStructuralFeatureValueAction::QUmlAddStructuralFeatureValueAction(bool createQModelingObject) :
    _insertAt(0),
    _isReplaceAll(false)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlAddStructuralFeatureValueActionObject(this));
}

/*!
    Destroys the QUmlAddStructuralFeatureValueAction.
 */
QUmlAddStructuralFeatureValueAction::~QUmlAddStructuralFeatureValueAction()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlAddStructuralFeatureValueAction.
*/
QModelingElement *QUmlAddStructuralFeatureValueAction::clone() const
{
    QUmlAddStructuralFeatureValueAction *c = new QUmlAddStructuralFeatureValueAction;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    foreach (QUmlExceptionHandler *element, handlers())
        c->addHandler(dynamic_cast<QUmlExceptionHandler *>(element->clone()));
    c->setLocallyReentrant(isLocallyReentrant());
    foreach (QUmlConstraint *element, localPostconditions())
        c->addLocalPostcondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlConstraint *element, localPreconditions())
        c->addLocalPrecondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    if (object())
        c->setObject(dynamic_cast<QUmlInputPin *>(object()->clone()));
    if (result())
        c->setResult(dynamic_cast<QUmlOutputPin *>(result()->clone()));
    if (value())
        c->setValue(dynamic_cast<QUmlInputPin *>(value()->clone()));
    if (insertAt())
        c->setInsertAt(dynamic_cast<QUmlInputPin *>(insertAt()->clone()));
    c->setReplaceAll(isReplaceAll());
    return c;
}

// OWNED ATTRIBUTES

/*!
    Gives the position at which to insert a new value or move an existing value in ordered structural features. The type of the pin is UnlimitedNatural, but the value cannot be zero. This pin is omitted for unordered structural features.

    \b {Subsetted property(ies):} QUmlAction::inputs().
 */
QUmlInputPin *QUmlAddStructuralFeatureValueAction::insertAt() const
{
    // This is a read-write association end

    return _insertAt;
}

/*!
    Adjusts insertAt to \a insertAt.
 */
void QUmlAddStructuralFeatureValueAction::setInsertAt(QUmlInputPin *insertAt)
{
    // This is a read-write association end

    if (_insertAt != insertAt) {
        // Adjust subsetted properties
        removeInput(_insertAt);

        _insertAt = insertAt;
        if (insertAt && insertAt->asQModelingObject() && this->asQModelingObject())
            QObject::connect(insertAt->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setInsertAt()));
        insertAt->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        if (insertAt) {
            addInput(insertAt);
        }
    }
}

/*!
    Specifies whether existing values of the structural feature of the object should be removed before adding the new value.
 */
bool QUmlAddStructuralFeatureValueAction::isReplaceAll() const
{
    // This is a read-write property

    return _isReplaceAll;
}

/*!
    Adjusts isReplaceAll to \a isReplaceAll.
 */
void QUmlAddStructuralFeatureValueAction::setReplaceAll(bool isReplaceAll)
{
    // This is a read-write property

    if (_isReplaceAll != isReplaceAll) {
        _isReplaceAll = isReplaceAll;
        _qModelingObject->modifiedResettableProperties() << QStringLiteral("isReplaceAll");
    }
}

QT_END_NAMESPACE

