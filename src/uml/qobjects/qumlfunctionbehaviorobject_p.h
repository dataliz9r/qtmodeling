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
#ifndef QUMLFUNCTIONBEHAVIOROBJECT_H
#define QUMLFUNCTIONBEHAVIOROBJECT_H

#include <QtUml/QtUmlGlobal>

#include <QtCore/QObject>

#include <QtUml/QtUmlNamespace>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlFunctionBehavior;
class Q_UML_EXPORT QUmlFunctionBehaviorObject : public QObject
{
    Q_OBJECT

    // Properties [Element]
    Q_PROPERTY(QSet<QObject *> ownedComment READ ownedComments)
    Q_PROPERTY(QSet<QObject *> ownedElement READ ownedElements)
    Q_PROPERTY(QObject * owner READ owner)

    // Properties [NamedElement]
    Q_PROPERTY(QSet<QObject *> clientDependency READ clientDependencies)
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QObject * nameExpression READ nameExpression)
    Q_PROPERTY(QObject * namespace_ READ namespace_)
    Q_PROPERTY(QString qualifiedName READ qualifiedName STORED false)

    // Properties [Namespace]
    Q_PROPERTY(QSet<QObject *> elementImport READ elementImports)
    Q_PROPERTY(QSet<QObject *> importedMember READ importedMembers STORED false)
    Q_PROPERTY(QSet<QObject *> member READ members)
    Q_PROPERTY(QSet<QObject *> ownedMember READ ownedMembers)
    Q_PROPERTY(QSet<QObject *> ownedRule READ ownedRules)
    Q_PROPERTY(QSet<QObject *> packageImport READ packageImports)

    // Properties [ParameterableElement]
    Q_PROPERTY(QObject * owningTemplateParameter READ owningTemplateParameter)

    // Properties [PackageableElement]
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility RESET unsetVisibility)

    // Properties [Type]
    Q_PROPERTY(QObject * package READ package)

    // Properties [RedefinableElement]
    Q_PROPERTY(bool isLeaf READ isLeaf RESET unsetLeaf)
    Q_PROPERTY(QSet<QObject *> redefinedElement READ redefinedElements)
    Q_PROPERTY(QSet<QObject *> redefinitionContext READ redefinitionContexts)

    // Properties [TemplateableElement]
    Q_PROPERTY(QSet<QObject *> templateBinding READ templateBindings)

    // Properties [Classifier]
    Q_PROPERTY(QSet<QObject *> attribute READ attributes)
    Q_PROPERTY(QSet<QObject *> collaborationUse READ collaborationUses)
    Q_PROPERTY(QSet<QObject *> feature READ features)
    Q_PROPERTY(QSet<QObject *> generalization READ generalizations)
    Q_PROPERTY(QSet<QObject *> inheritedMember READ inheritedMembers STORED false)
    Q_PROPERTY(bool isFinalSpecialization READ isFinalSpecialization RESET unsetFinalSpecialization)
    Q_PROPERTY(QObject * ownedTemplateSignature READ ownedTemplateSignature)
    Q_PROPERTY(QSet<QObject *> ownedUseCase READ ownedUseCases)
    Q_PROPERTY(QSet<QObject *> powertypeExtent READ powertypeExtents)
    Q_PROPERTY(QSet<QObject *> redefinedClassifier READ redefinedClassifiers)
    Q_PROPERTY(QObject * representation READ representation)
    Q_PROPERTY(QSet<QObject *> substitution READ substitutions)
    Q_PROPERTY(QObject * templateParameter READ templateParameter)
    Q_PROPERTY(QSet<QObject *> useCase READ useCases)

    // Properties [StructuredClassifier]
    Q_PROPERTY(QSet<QObject *> ownedConnector READ ownedConnectors)
    Q_PROPERTY(QSet<QObject *> part READ parts STORED false)
    Q_PROPERTY(QSet<QObject *> role READ roles)

    // Properties [EncapsulatedClassifier]
    Q_PROPERTY(QSet<QObject *> ownedPort READ ownedPorts STORED false)

    // Properties [BehavioredClassifier]
    Q_PROPERTY(QObject * classifierBehavior READ classifierBehavior)
    Q_PROPERTY(QSet<QObject *> interfaceRealization READ interfaceRealizations)
    Q_PROPERTY(QSet<QObject *> ownedBehavior READ ownedBehaviors)

    // Properties [Class]
    Q_PROPERTY(QSet<QObject *> extension READ extensions STORED false)
    Q_PROPERTY(bool isAbstract READ isAbstract RESET unsetAbstract)
    Q_PROPERTY(bool isActive READ isActive RESET unsetActive)
    Q_PROPERTY(QList<QObject *> nestedClassifier READ nestedClassifiers)
    Q_PROPERTY(QList<QObject *> ownedAttribute READ ownedAttributes)
    Q_PROPERTY(QList<QObject *> ownedOperation READ ownedOperations)
    Q_PROPERTY(QSet<QObject *> ownedReception READ ownedReceptions)
    Q_PROPERTY(QSet<QObject *> superClass READ superClasses STORED false)

    // Properties [Behavior]
    Q_PROPERTY(QObject * context READ context STORED false)
    Q_PROPERTY(bool isReentrant READ isReentrant RESET unsetReentrant)
    Q_PROPERTY(QList<QObject *> ownedParameter READ ownedParameters)
    Q_PROPERTY(QSet<QObject *> ownedParameterSet READ ownedParameterSets)
    Q_PROPERTY(QSet<QObject *> postcondition READ postconditions)
    Q_PROPERTY(QSet<QObject *> precondition READ preconditions)
    Q_PROPERTY(QSet<QObject *> redefinedBehavior READ redefinedBehaviors)
    Q_PROPERTY(QObject * specification READ specification)

    // Properties [OpaqueBehavior]
    Q_PROPERTY(QList<QString> body READ bodies)
    Q_PROPERTY(QList<QString> language READ languages)

public:
    Q_INVOKABLE explicit QUmlFunctionBehaviorObject(QUmlFunctionBehavior *qModelingObject);
    virtual ~QUmlFunctionBehaviorObject();

    // Owned attributes [Element]
    Q_INVOKABLE const QSet<QObject *> ownedComments() const;
    Q_INVOKABLE const QSet<QObject *> ownedElements() const;
    Q_INVOKABLE QObject *owner() const;

    // Owned attributes [NamedElement]
    Q_INVOKABLE const QSet<QObject *> clientDependencies() const;
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE QObject *nameExpression() const;
    Q_INVOKABLE QObject *namespace_() const;
    Q_INVOKABLE QString qualifiedName() const;

    // Owned attributes [Namespace]
    Q_INVOKABLE const QSet<QObject *> elementImports() const;
    Q_INVOKABLE const QSet<QObject *> importedMembers() const;
    Q_INVOKABLE const QSet<QObject *> members() const;
    Q_INVOKABLE const QSet<QObject *> ownedMembers() const;
    Q_INVOKABLE const QSet<QObject *> ownedRules() const;
    Q_INVOKABLE const QSet<QObject *> packageImports() const;

    // Owned attributes [ParameterableElement]
    Q_INVOKABLE QObject *owningTemplateParameter() const;

    // Owned attributes [PackageableElement]
    Q_INVOKABLE QtUml::VisibilityKind visibility() const;

    // Owned attributes [Type]
    Q_INVOKABLE QObject *package() const;

    // Owned attributes [RedefinableElement]
    Q_INVOKABLE bool isLeaf() const;
    Q_INVOKABLE const QSet<QObject *> redefinedElements() const;
    Q_INVOKABLE const QSet<QObject *> redefinitionContexts() const;

    // Owned attributes [TemplateableElement]
    Q_INVOKABLE const QSet<QObject *> templateBindings() const;

    // Owned attributes [Classifier]
    Q_INVOKABLE const QSet<QObject *> attributes() const;
    Q_INVOKABLE const QSet<QObject *> collaborationUses() const;
    Q_INVOKABLE const QSet<QObject *> features() const;
    Q_INVOKABLE const QSet<QObject *> generalizations() const;
    Q_INVOKABLE const QSet<QObject *> inheritedMembers() const;
    Q_INVOKABLE bool isFinalSpecialization() const;
    Q_INVOKABLE QObject *ownedTemplateSignature() const;
    Q_INVOKABLE const QSet<QObject *> ownedUseCases() const;
    Q_INVOKABLE const QSet<QObject *> powertypeExtents() const;
    Q_INVOKABLE const QSet<QObject *> redefinedClassifiers() const;
    Q_INVOKABLE QObject *representation() const;
    Q_INVOKABLE const QSet<QObject *> substitutions() const;
    Q_INVOKABLE QObject *templateParameter() const;
    Q_INVOKABLE const QSet<QObject *> useCases() const;

    // Owned attributes [StructuredClassifier]
    Q_INVOKABLE const QSet<QObject *> ownedConnectors() const;
    Q_INVOKABLE const QSet<QObject *> parts() const;
    Q_INVOKABLE const QSet<QObject *> roles() const;

    // Owned attributes [EncapsulatedClassifier]
    Q_INVOKABLE const QSet<QObject *> ownedPorts() const;

    // Owned attributes [BehavioredClassifier]
    Q_INVOKABLE QObject *classifierBehavior() const;
    Q_INVOKABLE const QSet<QObject *> interfaceRealizations() const;
    Q_INVOKABLE const QSet<QObject *> ownedBehaviors() const;

    // Owned attributes [Class]
    Q_INVOKABLE const QSet<QObject *> extensions() const;
    Q_INVOKABLE bool isAbstract() const;
    Q_INVOKABLE bool isActive() const;
    Q_INVOKABLE const QList<QObject *> nestedClassifiers() const;
    Q_INVOKABLE const QList<QObject *> ownedAttributes() const;
    Q_INVOKABLE const QList<QObject *> ownedOperations() const;
    Q_INVOKABLE const QSet<QObject *> ownedReceptions() const;
    Q_INVOKABLE const QSet<QObject *> superClasses() const;

    // Owned attributes [Behavior]
    Q_INVOKABLE QObject *context() const;
    Q_INVOKABLE bool isReentrant() const;
    Q_INVOKABLE const QList<QObject *> ownedParameters() const;
    Q_INVOKABLE const QSet<QObject *> ownedParameterSets() const;
    Q_INVOKABLE const QSet<QObject *> postconditions() const;
    Q_INVOKABLE const QSet<QObject *> preconditions() const;
    Q_INVOKABLE const QSet<QObject *> redefinedBehaviors() const;
    Q_INVOKABLE QObject *specification() const;

    // Owned attributes [OpaqueBehavior]
    Q_INVOKABLE const QList<QString> bodies() const;
    Q_INVOKABLE const QList<QString> languages() const;

    // Operations [Element]
    Q_INVOKABLE QSet<QObject *> allOwnedElements() const;
    Q_INVOKABLE bool mustBeOwned() const;

    // Operations [NamedElement]
    Q_INVOKABLE QList<QObject *> allNamespaces() const;
    Q_INVOKABLE QSet<QObject *> allOwningPackages() const;
    Q_INVOKABLE bool isDistinguishableFrom(QObject *n, QObject *ns) const;
    Q_INVOKABLE QString separator() const;

    // Operations [Namespace]
    Q_INVOKABLE QSet<QObject *> excludeCollisions(QSet<QObject *> imps) const;
    Q_INVOKABLE QSet<QString> getNamesOfMember(QObject *element) const;
    Q_INVOKABLE QSet<QObject *> importMembers(QSet<QObject *> imps) const;
    Q_INVOKABLE bool membersAreDistinguishable() const;

    // Operations [ParameterableElement]
    Q_INVOKABLE bool isCompatibleWith(QObject *p) const;
    Q_INVOKABLE bool isTemplateParameter() const;

    // Operations [Type]

    // Operations [RedefinableElement]
    Q_INVOKABLE bool isConsistentWith(QObject *redefinee) const;
    Q_INVOKABLE bool isRedefinitionContextValid(QObject *redefined) const;

    // Operations [TemplateableElement]
    Q_INVOKABLE QSet<QObject *> parameterableElements() const;

    // Operations [Classifier]
    Q_INVOKABLE QSet<QObject *> allFeatures() const;
    Q_INVOKABLE QSet<QObject *> allParents() const;
    Q_INVOKABLE bool conformsTo(QObject *other) const;
    Q_INVOKABLE bool hasVisibilityOf(QObject *n) const;
    Q_INVOKABLE QSet<QObject *> inheritableMembers(QObject *c) const;
    Q_INVOKABLE bool isTemplate() const;
    Q_INVOKABLE bool maySpecializeType(QObject *c) const;
    Q_INVOKABLE QSet<QObject *> parents() const;

    // Operations [Class]
    Q_INVOKABLE QSet<QObject *> inherit(QSet<QObject *> inhs) const;

public Q_SLOTS:

    // Slots for owned attributes [Element]
    void addOwnedComment(QObject *ownedComment);
    void removeOwnedComment(QObject *ownedComment);
    void Q_DECL_HIDDEN addOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN removeOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN setOwner(QObject *owner = 0);

    // Slots for owned attributes [NamedElement]
    void addClientDependency(QObject *clientDependency);
    void removeClientDependency(QObject *clientDependency);
    void setName(QString name);
    void setNameExpression(QObject *nameExpression = 0);
    void Q_DECL_HIDDEN setNamespace(QObject *namespace_ = 0);
    void Q_DECL_HIDDEN setQualifiedName(QString qualifiedName);

    // Slots for owned attributes [Namespace]
    void addElementImport(QObject *elementImport);
    void removeElementImport(QObject *elementImport);
    void Q_DECL_HIDDEN addImportedMember(QObject *importedMember);
    void Q_DECL_HIDDEN removeImportedMember(QObject *importedMember);
    void Q_DECL_HIDDEN addMember(QObject *member);
    void Q_DECL_HIDDEN removeMember(QObject *member);
    void Q_DECL_HIDDEN addOwnedMember(QObject *ownedMember);
    void Q_DECL_HIDDEN removeOwnedMember(QObject *ownedMember);
    void addOwnedRule(QObject *ownedRule);
    void removeOwnedRule(QObject *ownedRule);
    void addPackageImport(QObject *packageImport);
    void removePackageImport(QObject *packageImport);

    // Slots for owned attributes [ParameterableElement]
    void setOwningTemplateParameter(QObject *owningTemplateParameter = 0);

    // Slots for owned attributes [PackageableElement]
    void setVisibility(QtUml::VisibilityKind visibility);
    void unsetVisibility();

    // Slots for owned attributes [Type]
    void setPackage(QObject *package = 0);

    // Slots for owned attributes [RedefinableElement]
    void setLeaf(bool isLeaf);
    void unsetLeaf();
    void Q_DECL_HIDDEN addRedefinedElement(QObject *redefinedElement);
    void Q_DECL_HIDDEN removeRedefinedElement(QObject *redefinedElement);
    void Q_DECL_HIDDEN addRedefinitionContext(QObject *redefinitionContext);
    void Q_DECL_HIDDEN removeRedefinitionContext(QObject *redefinitionContext);

    // Slots for owned attributes [TemplateableElement]
    void addTemplateBinding(QObject *templateBinding);
    void removeTemplateBinding(QObject *templateBinding);

    // Slots for owned attributes [Classifier]
    void Q_DECL_HIDDEN addAttribute(QObject *attribute);
    void Q_DECL_HIDDEN removeAttribute(QObject *attribute);
    void addCollaborationUse(QObject *collaborationUse);
    void removeCollaborationUse(QObject *collaborationUse);
    void Q_DECL_HIDDEN addFeature(QObject *feature);
    void Q_DECL_HIDDEN removeFeature(QObject *feature);
    void addGeneralization(QObject *generalization);
    void removeGeneralization(QObject *generalization);
    void Q_DECL_HIDDEN addInheritedMember(QObject *inheritedMember);
    void Q_DECL_HIDDEN removeInheritedMember(QObject *inheritedMember);
    void setFinalSpecialization(bool isFinalSpecialization);
    void unsetFinalSpecialization();
    void setOwnedTemplateSignature(QObject *ownedTemplateSignature = 0);
    void addOwnedUseCase(QObject *ownedUseCase);
    void removeOwnedUseCase(QObject *ownedUseCase);
    void addPowertypeExtent(QObject *powertypeExtent);
    void removePowertypeExtent(QObject *powertypeExtent);
    void addRedefinedClassifier(QObject *redefinedClassifier);
    void removeRedefinedClassifier(QObject *redefinedClassifier);
    void setRepresentation(QObject *representation = 0);
    void addSubstitution(QObject *substitution);
    void removeSubstitution(QObject *substitution);
    void setTemplateParameter(QObject *templateParameter = 0);
    void addUseCase(QObject *useCase);
    void removeUseCase(QObject *useCase);

    // Slots for owned attributes [StructuredClassifier]
    void addOwnedConnector(QObject *ownedConnector);
    void removeOwnedConnector(QObject *ownedConnector);
    void Q_DECL_HIDDEN addPart(QObject *part);
    void Q_DECL_HIDDEN removePart(QObject *part);
    void Q_DECL_HIDDEN addRole(QObject *role);
    void Q_DECL_HIDDEN removeRole(QObject *role);

    // Slots for owned attributes [EncapsulatedClassifier]
    void Q_DECL_HIDDEN addOwnedPort(QObject *ownedPort);
    void Q_DECL_HIDDEN removeOwnedPort(QObject *ownedPort);

    // Slots for owned attributes [BehavioredClassifier]
    void setClassifierBehavior(QObject *classifierBehavior = 0);
    void addInterfaceRealization(QObject *interfaceRealization);
    void removeInterfaceRealization(QObject *interfaceRealization);
    void addOwnedBehavior(QObject *ownedBehavior);
    void removeOwnedBehavior(QObject *ownedBehavior);

    // Slots for owned attributes [Class]
    void Q_DECL_HIDDEN addExtension(QObject *extension);
    void Q_DECL_HIDDEN removeExtension(QObject *extension);
    void setAbstract(bool isAbstract);
    void unsetAbstract();
    void setActive(bool isActive);
    void unsetActive();
    void addNestedClassifier(QObject *nestedClassifier);
    void removeNestedClassifier(QObject *nestedClassifier);
    void addOwnedAttribute(QObject *ownedAttribute);
    void removeOwnedAttribute(QObject *ownedAttribute);
    void addOwnedOperation(QObject *ownedOperation);
    void removeOwnedOperation(QObject *ownedOperation);
    void addOwnedReception(QObject *ownedReception);
    void removeOwnedReception(QObject *ownedReception);
    void addSuperClass(QObject *superClass);
    void removeSuperClass(QObject *superClass);

    // Slots for owned attributes [Behavior]
    void Q_DECL_HIDDEN setContext(QObject *context = 0);
    void setReentrant(bool isReentrant);
    void unsetReentrant();
    void addOwnedParameter(QObject *ownedParameter);
    void removeOwnedParameter(QObject *ownedParameter);
    void addOwnedParameterSet(QObject *ownedParameterSet);
    void removeOwnedParameterSet(QObject *ownedParameterSet);
    void addPostcondition(QObject *postcondition);
    void removePostcondition(QObject *postcondition);
    void addPrecondition(QObject *precondition);
    void removePrecondition(QObject *precondition);
    void addRedefinedBehavior(QObject *redefinedBehavior);
    void removeRedefinedBehavior(QObject *redefinedBehavior);
    void setSpecification(QObject *specification = 0);

    // Slots for owned attributes [OpaqueBehavior]
    void addBody(QString body);
    void removeBody(QString body);
    void addLanguage(QString language);
    void removeLanguage(QString language);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QUMLFUNCTIONBEHAVIOROBJECT_H

