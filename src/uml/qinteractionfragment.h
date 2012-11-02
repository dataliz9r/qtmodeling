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
** rights. These rights are described in the Nokia  LGPL Exception
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
#ifndef QTUML_QINTERACTIONFRAGMENT_H
#define QTUML_QINTERACTIONFRAGMENT_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QNamedElement>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QGeneralOrdering;
class QInteractionOperand;
class QLifeline;
class QInteraction;

class QInteractionFragmentPrivate;

class Q_UML_EXPORT QInteractionFragment : public QNamedElement
{
    Q_OBJECT

    // From QInteractionFragment
    Q_PROPERTY(const QSet<QGeneralOrdering *> * generalOrderings READ generalOrderings)
    Q_PROPERTY(QInteraction * enclosingInteraction READ enclosingInteraction WRITE setEnclosingInteraction)
    Q_PROPERTY(const QSet<QLifeline *> * covered READ covered)
    Q_PROPERTY(QInteractionOperand * enclosingOperand READ enclosingOperand WRITE setEnclosingOperand)

    Q_DISABLE_COPY(QInteractionFragment)
    Q_DECLARE_PRIVATE(QInteractionFragment)

public:
    explicit QInteractionFragment(QObject *parent = 0);
    virtual ~QInteractionFragment();

    // Association-ends
    const QSet<QGeneralOrdering *> *generalOrderings() const;
    void addGeneralOrdering(QGeneralOrdering *generalOrdering);
    void removeGeneralOrdering(QGeneralOrdering *generalOrdering);
    QInteraction *enclosingInteraction() const;
    void setEnclosingInteraction(QInteraction *enclosingInteraction);
    const QSet<QLifeline *> *covered() const;
    void addCovered(QLifeline *covered);
    void removeCovered(QLifeline *covered);
    QInteractionOperand *enclosingOperand() const;
    void setEnclosingOperand(QInteractionOperand *enclosingOperand);

protected:
    explicit QInteractionFragment(QInteractionFragmentPrivate &dd, QObject *parent = 0);
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QInteractionFragment) *)
Q_DECLARE_METATYPE(QSet<QT_PREPEND_NAMESPACE_QTUML(QInteractionFragment) *> *)
Q_DECLARE_METATYPE(QList<QT_PREPEND_NAMESPACE_QTUML(QInteractionFragment) *> *)

QT_END_HEADER

#endif // QTUML_QINTERACTIONFRAGMENT_H

