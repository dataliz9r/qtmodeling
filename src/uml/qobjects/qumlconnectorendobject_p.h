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
#ifndef QUMLCONNECTORENDOBJECT_H
#define QUMLCONNECTORENDOBJECT_H

#include <QtUml/QtUmlGlobal>

#include <QtModeling/QModelingObject>

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlConnectorEnd;
class QModelingObjectPrivate;
class Q_UML_EXPORT QUmlConnectorEndObject : public QModelingObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QUmlConnectorEndObject)
    Q_DECLARE_PRIVATE(QModelingObject)

    // Properties [Element]
    Q_PROPERTY(QSet<QObject *> ownedComments READ ownedComments NOTIFY ownedCommentsChanged)
    Q_PROPERTY(QSet<QObject *> ownedElements READ ownedElements NOTIFY ownedElementsChanged)
    Q_PROPERTY(QObject * owner READ owner NOTIFY ownerChanged)

    // Properties [MultiplicityElement]
    Q_PROPERTY(bool isOrdered READ isOrdered WRITE setOrdered NOTIFY isOrderedChanged RESET unsetOrdered)
    Q_PROPERTY(bool isUnique READ isUnique WRITE setUnique NOTIFY isUniqueChanged RESET unsetUnique)
    Q_PROPERTY(int lower READ lower WRITE setLower NOTIFY lowerChanged RESET unsetLower STORED false)
    Q_PROPERTY(QObject * lowerValue READ lowerValue WRITE setLowerValue NOTIFY lowerValueChanged)
    Q_PROPERTY(QString upper READ upper WRITE setUpper NOTIFY upperChanged RESET unsetUpper STORED false)
    Q_PROPERTY(QObject * upperValue READ upperValue WRITE setUpperValue NOTIFY upperValueChanged)

    // Properties [ConnectorEnd]
    Q_PROPERTY(QObject * definingEnd READ definingEnd NOTIFY definingEndChanged STORED false)
    Q_PROPERTY(QObject * partWithPort READ partWithPort WRITE setPartWithPort NOTIFY partWithPortChanged)
    Q_PROPERTY(QObject * role READ role WRITE setRole NOTIFY roleChanged)

public:
    Q_INVOKABLE explicit QUmlConnectorEndObject(QUmlConnectorEnd *modelingElement);

    // Owned attributes [Element]
    Q_INVOKABLE const QSet<QObject *> ownedComments() const;
    Q_INVOKABLE const QSet<QObject *> ownedElements() const;
    Q_INVOKABLE QObject *owner() const;

    // Owned attributes [MultiplicityElement]
    Q_INVOKABLE bool isOrdered() const;
    Q_INVOKABLE bool isUnique() const;
    Q_TODO Q_INVOKABLE int lower() const;
    Q_INVOKABLE QObject *lowerValue() const;
    Q_TODO Q_INVOKABLE QString upper() const;
    Q_INVOKABLE QObject *upperValue() const;

    // Owned attributes [ConnectorEnd]
    Q_TODO Q_INVOKABLE QObject *definingEnd() const;
    Q_INVOKABLE QObject *partWithPort() const;
    Q_INVOKABLE QObject *role() const;

    // Operations [Element]
    Q_INVOKABLE QSet<QObject *> allOwnedElements() const;
    Q_INVOKABLE bool mustBeOwned() const;

    // Operations [MultiplicityElement]
    Q_TODO Q_INVOKABLE bool compatibleWith(QObject *other) const;
    Q_TODO Q_INVOKABLE bool includesCardinality(int C) const;
    Q_TODO Q_INVOKABLE bool includesMultiplicity(QObject *M) const;
    Q_TODO Q_INVOKABLE bool is(int lowerbound, int upperbound) const;
    Q_TODO Q_INVOKABLE bool isMultivalued() const;
    Q_TODO Q_INVOKABLE int lowerBound() const;
    Q_TODO Q_INVOKABLE QString upperBoundOperation() const;

public Q_SLOTS:

    // Slots for owned attributes [Element]
    void addOwnedComment(QObject *ownedComment);
    void removeOwnedComment(QObject *ownedComment);
    void Q_DECL_HIDDEN addOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN removeOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN setOwner(QObject *owner = 0);

    // Slots for owned attributes [MultiplicityElement]
    void setOrdered(bool isOrdered);
    void unsetOrdered();
    void setUnique(bool isUnique);
    void unsetUnique();
    void setLower(int lower);
    void unsetLower();
    void setLowerValue(QObject *lowerValue = 0);
    void setUpper(QString upper);
    void unsetUpper();
    void setUpperValue(QObject *upperValue = 0);

    // Slots for owned attributes [ConnectorEnd]
    void Q_DECL_HIDDEN setDefiningEnd(QObject *definingEnd = 0);
    void setPartWithPort(QObject *partWithPort = 0);
    void setRole(QObject *role = 0);

Q_SIGNALS:

    // Signals for owned attributes [Element]
    void ownedCommentsChanged(QSet<QObject *> ownedComments);
    void ownedElementsChanged(QSet<QObject *> ownedElements);
    void ownerChanged(QObject *owner);

    // Signals for owned attributes [MultiplicityElement]
    void isOrderedChanged(bool isOrdered);
    void isUniqueChanged(bool isUnique);
    void lowerChanged(int lower);
    void lowerValueChanged(QObject *lowerValue);
    void upperChanged(QString upper);
    void upperValueChanged(QObject *upperValue);

    // Signals for owned attributes [ConnectorEnd]
    void definingEndChanged(QObject *definingEnd);
    void partWithPortChanged(QObject *partWithPort);
    void roleChanged(QObject *role);

protected:
    virtual void setGroupProperties();
    virtual void setPropertyData();
};

QT_END_NAMESPACE

#endif // QUMLCONNECTORENDOBJECT_H

