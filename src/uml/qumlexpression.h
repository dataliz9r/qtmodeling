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
#ifndef QUMLEXPRESSION_H
#define QUMLEXPRESSION_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QUmlValueSpecification>

// Qt includes
#include <QtCore/QString>
#include <QtCore/QList>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlExpressionPrivate;

class Q_UML_EXPORT QUmlExpression : public QUmlValueSpecification
{
    Q_OBJECT
    Q_CLASSINFO("MetaModelPrefix", "QUml")

    Q_PROPERTY(QString symbol READ symbol WRITE setSymbol)
    Q_PROPERTY(QList<QUmlValueSpecification *> operands READ operands)

    Q_DISABLE_COPY(QUmlExpression)
    Q_DECLARE_PRIVATE(QUmlExpression)

public:
    Q_INVOKABLE explicit QUmlExpression(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QUmlExpression();

    // Attributes from QUmlExpression
    Q_INVOKABLE QString symbol() const;
    Q_INVOKABLE void setSymbol(QString symbol);

    // Association ends from QUmlExpression
    Q_INVOKABLE QList<QUmlValueSpecification *> operands() const;
    Q_INVOKABLE void addOperand(QUmlValueSpecification *operand);
    Q_INVOKABLE void removeOperand(QUmlValueSpecification *operand);

    virtual void setPropertyData();

protected:
    explicit QUmlExpression(QUmlExpressionPrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QUMLEXPRESSION_H
