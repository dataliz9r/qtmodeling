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
#ifndef QTUML_QVARIABLE_H
#define QTUML_QVARIABLE_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtCore/QObject>
#include <QtUml/QMultiplicityElement>
#include <QtUml/QConnectableElement>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QActivity;
class QStructuredActivityNode;
class QAction;

class QVariablePrivate;

class Q_UML_EXPORT QVariable : public QObject
{
    Q_OBJECT

    // From aggregated QElement
    Q_PROPERTY(const QSet<QElement *> * ownedElements READ ownedElements)
    Q_PROPERTY(QElement * owner READ owner)
    Q_PROPERTY(const QSet<QComment *> * ownedComments READ ownedComments)

    // From aggregated QMultiplicityElement
    Q_PROPERTY(qint32 upper READ upper WRITE setUpper STORED false)
    Q_PROPERTY(bool isUnique READ isUnique WRITE setUnique)
    Q_PROPERTY(bool isOrdered READ isOrdered WRITE setOrdered)
    Q_PROPERTY(qint32 lower READ lower WRITE setLower STORED false)
    Q_PROPERTY(QValueSpecification * upperValue READ upperValue WRITE setUpperValue)
    Q_PROPERTY(QValueSpecification * lowerValue READ lowerValue WRITE setLowerValue)

    // From aggregated QNamedElement
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QString qualifiedName READ qualifiedName STORED false)
    Q_PROPERTY(QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QNamespace * namespace_ READ namespace_)
    Q_PROPERTY(const QSet<QDependency *> * clientDependencies READ clientDependencies)

    // From aggregated QTypedElement
    Q_PROPERTY(QType * type READ type WRITE setType)

    // From aggregated QParameterableElement
    Q_PROPERTY(QTemplateParameter * owningTemplateParameter READ owningTemplateParameter WRITE setOwningTemplateParameter)

    // From aggregated QConnectableElement
    Q_PROPERTY(const QList<QConnectorEnd *> * ends READ ends STORED false)
    Q_PROPERTY(QConnectableElementTemplateParameter * templateParameter READ templateParameter WRITE setTemplateParameter)

    // From QVariable
    Q_PROPERTY(QStructuredActivityNode * scope READ scope WRITE setScope)
    Q_PROPERTY(QActivity * activityScope READ activityScope WRITE setActivityScope)

    Q_DISABLE_COPY(QVariable)
    Q_DECLARE_PRIVATE(QVariable)

public:
    explicit QVariable(QObject *parent = 0);
    virtual ~QVariable();

    // Association ends from aggregated QElement
    const QSet<QElement *> *ownedElements() const;
    QElement *owner() const;
    const QSet<QComment *> *ownedComments() const;
    void addOwnedComment(QComment *ownedComment);
    void removeOwnedComment(QComment *ownedComment);

    // Attributes from aggregated QMultiplicityElement
    qint32 upper() const;
    void setUpper(qint32 upper);
    bool isUnique() const;
    void setUnique(bool isUnique);
    bool isOrdered() const;
    void setOrdered(bool isOrdered);
    qint32 lower() const;
    void setLower(qint32 lower);

    // Association ends from aggregated QMultiplicityElement
    QValueSpecification *upperValue() const;
    void setUpperValue(QValueSpecification *upperValue);
    QValueSpecification *lowerValue() const;
    void setLowerValue(QValueSpecification *lowerValue);

    // Attributes from aggregated QNamedElement
    QString name() const;
    void setName(QString name);
    QtUml::VisibilityKind visibility() const;
    void setVisibility(QtUml::VisibilityKind visibility);
    QString qualifiedName() const;

    // Association ends from aggregated QNamedElement
    QStringExpression *nameExpression() const;
    void setNameExpression(QStringExpression *nameExpression);
    QNamespace *namespace_() const;
    const QSet<QDependency *> *clientDependencies() const;
    void addClientDependency(QDependency *clientDependency);
    void removeClientDependency(QDependency *clientDependency);

    // Association ends from aggregated QTypedElement
    QType *type() const;
    void setType(QType *type);

    // Association ends from aggregated QParameterableElement
    QTemplateParameter *owningTemplateParameter() const;
    void setOwningTemplateParameter(QTemplateParameter *owningTemplateParameter);

    // Association ends from aggregated QConnectableElement
    const QList<QConnectorEnd *> *ends() const;
    QConnectableElementTemplateParameter *templateParameter() const;
    void setTemplateParameter(QConnectableElementTemplateParameter *templateParameter);

    // Association ends from QVariable
    QStructuredActivityNode *scope() const;
    void setScope(QStructuredActivityNode *scope);
    QActivity *activityScope() const;
    void setActivityScope(QActivity *activityScope);

    // Operations
    bool isAccessibleBy(const QAction *a) const;

protected:
    explicit QVariable(QVariablePrivate &dd, QObject *parent = 0);

private:
    QMultiplicityElement *_wrappedMultiplicityElement;
    QConnectableElement *_wrappedConnectableElement;
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QVariable) *)
Q_DECLARE_METATYPE(const QSet<QT_PREPEND_NAMESPACE_QTUML(QVariable) *> *)
Q_DECLARE_METATYPE(const QList<QT_PREPEND_NAMESPACE_QTUML(QVariable) *> *)

QT_END_HEADER

#endif // QTUML_QVARIABLE_H

