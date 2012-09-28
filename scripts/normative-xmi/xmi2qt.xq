declare namespace xmi="http://www.omg.org/spec/XMI/20110701";
declare namespace qtxmi="http://www.qt-project.org";

declare function qtxmi:typeStringFromProperty ($properties as node()*) as xs:string* {
    for $property in $properties
    let $type := if ($property/@type) then xs:string($property/@type)
                 else if ($property/type/@xmi:idref) then xs:string($property/type/@xmi:idref)
                 else if ($property/type/@href) then xs:string($property/type/@href)
                 else "qtxmi:unknownType"
    let $type := tokenize($type, "/")[last()]
    return $type
};

declare function qtxmi:mappedBaseNamespace($xmiFile as xs:string*) as xs:string* {
    if ($xmiFile = "PrimitiveTypes.xmi") then ""
    else if ($xmiFile = "Superstructure.xmi") then "QtUml::"
    else if ($xmiFile = "MOF.xmi") then "QtMof::"
    else ""
};

declare function qtxmi:namespaceFromTypeString ($types as xs:string*) as xs:string* {
    for $type in $types
    let $type := tokenize($type, "/")[last()]
    let $baseNamespace := tokenize($type, "#")[1]
    let $type := tokenize($type, "#")[last()]
    let $baseNamespace := qtxmi:mappedBaseNamespace(if ($baseNamespace = $type) then $xmiFile else $baseNamespace)
    let $namespaceArray := tokenize($type, "-")
    return concat(concat($baseNamespace, string-join(remove($namespaceArray, count($namespaceArray)), "::")), "::")
};

declare function qtxmi:namespaceFromProperty ($properties as node()*) as xs:string* {
    qtxmi:namespaceFromTypeString(qtxmi:typeStringFromProperty($properties))
};

declare function qtxmi:unqualifiedTypeFromTypeString ($types as xs:string*) as xs:string* {
    for $type in $types
    let $type := tokenize($type, "/")[last()]
    let $type := tokenize($type, "#")[last()]
    return tokenize($type, "-")[last()]
};

declare function qtxmi:unqualifiedTypeFromProperty ($properties as node()*) as xs:string* {
    qtxmi:unqualifiedTypeFromTypeString(qtxmi:typeStringFromProperty($properties))
};

declare function qtxmi:qualifiedTypeFromTypeString ($types as xs:string*) as xs:string* {
    concat(qtxmi:namespaceFromTypeString($types), qtxmi:unqualifiedTypeFromTypeString($types))
};

declare function qtxmi:qualifiedTypeFromProperty ($properties as node()*) as xs:string* {
    qtxmi:qualifiedTypeFromTypeString(qtxmi:typeStringFromProperty($properties))
};

declare function qtxmi:elementFromTypeString ($types as xs:string*) as node()* {
    for $type in $types
    let $type := tokenize($type, "/")[last()]
    let $file := tokenize($type, "#")[1]
    let $type := tokenize($type, "#")[last()]
    let $file := if ($file = $type) then $xmiFile else $file
    return
    doc($file)//packagedElement[@xmi:id = $type]
};

declare function qtxmi:elementFromProperty ($properties as node()*) as node()* {
    qtxmi:elementFromTypeString(qtxmi:typeStringFromProperty($properties))
};

declare function qtxmi:mappedPrimitiveType ($primitiveType as xs:string*) as xs:string* {
    if ($primitiveType = "Boolean") then "bool"
    else if ($primitiveType = "Integer" or $primitiveType = "UnlimitedNatural") then "qint32"
    else if ($primitiveType = "Real") then "qreal"
    else if ($primitiveType = "String") then "QString"
    else "qtxmi:unknownPrimitiveType"
};

declare function qtxmi:mappedFunctionName ($name as xs:string*) as xs:string* {
    if ($name = "namespace") then "namespace_"
    else if ($name = "class") then "class_"
    else if ($name = "default") then "default_"
    else $name
};

declare function qtxmi:unqualifiedTypeFromNamespacedProperty ($property as node(), $namespace as xs:string) as xs:string {
    let $type := qtxmi:unqualifiedTypeFromProperty($property)
    let $element := qtxmi:elementFromProperty($property)
    let $propertyNamespace := replace(qtxmi:namespaceFromProperty($property), $namespace, "")
    let $baseType := if ($element/@xmi:type = "uml:Class") then
                         concat($propertyNamespace, concat("Q", $type))
                     else if ($element/@xmi:type = "uml:Enumeration") then
                         concat($propertyNamespace, concat("QEnumerations::", $type))
                     else
                         qtxmi:mappedPrimitiveType($type)
    let $baseType := if ($property/upperValue/@value = "*") then concat(concat("QList<", $baseType), " *>") else $baseType
    let $baseType := if ($element/@xmi:type = "uml:Class" and ($property/@isReadOnly = "true" or $property/@isDerived = "true" or ($property/@direction = "return" and $property/../@isQuery = "true"))) then concat ("const ", $baseType) else $baseType
    let $baseType := if ($element/@xmi:type = "uml:Class") then concat ($baseType, " *") else $baseType
    return $baseType
};

declare function qtxmi:capitalizedNameFromTypeString ($unqualifiedType as xs:string, $name as xs:string) as xs:string {
    let $capitalizedName := $name
    let $capitalizedName := if ($unqualifiedType = "bool " and starts-with($name, "is") and substring($name, 3, 1) = upper-case(substring($name, 3, 1))) then
       substring($name, 3)
    else
       $capitalizedName
    return concat(upper-case(substring($capitalizedName, 1, 1)), substring($capitalizedName, 2))
};

<qtxmi:XMI xmlns:xmi="http://www.omg.org/spec/XMI/20110701" xmlns:uml="http://www.omg.org/spec/UML/20110701" xmlns:qtxmi="http://www.qt-project.org">
{
for $namespace in distinct-values(doc($xmiFile)//packagedElement[@xmi:type="uml:Package"][@xmi:id="Classes-Kernel"]/@xmi:id)
return
<namespace path="{replace(replace(concat(qtxmi:mappedBaseNamespace($xmiFile), $namespace), "-", "/"), "::", "/")}">
{
for $class in doc($xmiFile)//packagedElement[@xmi:id=$namespace]/packagedElement[@xmi:type="uml:Class"]
let $namespace := concat(replace(concat(qtxmi:mappedBaseNamespace($xmiFile), $namespace), "-", "::"), "::")
let $superClasses := $class/generalization/@general
let $isAbstract := if ($class/@isAbstract) then $class/@isAbstract else "false"
return
    <class name="Q{$class/@name}" isAbstract="{$isAbstract}">
        {
        if ($class/ownedComment/body) then
        <documentation>{$class/ownedComment/body/text()}</documentation>
        else ""
        }
        {
        for $id in distinct-values(qtxmi:elementFromProperty($class/ownedAttribute | $class/ownedOperation/ownedParameter)/@xmi:type)
        where $id = "uml:Enumeration"
        return
        <qtumlinclude>QtUml/QEnumerations</qtumlinclude>
        }
        {
        for $superobject in (qtxmi:elementFromTypeString($superClasses)[not(@isAbstract) or @isAbstract = "false"]/@xmi:id)
        return
        <superobject>QtCore/{concat("Q", qtxmi:unqualifiedTypeFromTypeString($superobject))}</superobject>
        }
        {
        if (count(qtxmi:elementFromTypeString($superClasses)[@isAbstract = "true"]) = count($superClasses) and $isAbstract = "false") then
        <superclassinclude>QtCore/QObject</superclassinclude>
        else ""
        }
        {
        for $id in $superClasses
        return
        <superclassinclude>QtUml/{concat("Q", qtxmi:unqualifiedTypeFromTypeString($id))}</superclassinclude>
        }
        {
        for $type in distinct-values($class/ownedAttribute/type/@href | $class/ownedOperation/ownedParameter/type/@href)
        where tokenize($type, "#")[last()] = "String"
        return
        <qtinclude>QtCore/QString</qtinclude>
        }
        {
        for $value in distinct-values($class/ownedAttribute/upperValue/@value | $class/ownedOperation/ownedParameter/upperValue/@Value)
        where $value = "*"
        return
        <qtinclude>QtCore/QList</qtinclude>
        }
        {
        for $id in distinct-values($class/ownedAttribute/@type | $class/ownedOperation/ownedParameter/@type | $class/ownedAttribute/type/@xmi:idref | $class/ownedOperation/ownedParameter/type/@xmi:idref | $class/ownedAttribute/type/@href | $class/ownedOperation/ownedParameter/type/@href)
        let $forwardNamespace := tokenize(qtxmi:namespaceFromTypeString($id), "::")
        let $forwardNamespace := string-join(remove($forwardNamespace, count($forwardNamespace)), "::")
        where qtxmi:elementFromTypeString($id)/@xmi:type = "uml:Class" and tokenize($id, "#")[last()] != $class/@xmi:id and empty(distinct-values($id[.=$superClasses]))
        return
        <forwarddecl namespace="{$forwardNamespace}">{concat("Q", qtxmi:unqualifiedTypeFromTypeString($id))}</forwarddecl>
        }
        {
        for $attribute in $class/ownedAttribute
        let $unqualifiedType := qtxmi:unqualifiedTypeFromNamespacedProperty($attribute, $namespace)
        let $unqualifiedType := if (ends-with($unqualifiedType, "*")) then $unqualifiedType else concat($unqualifiedType, " ")
        let $isDerived := if (not($attribute/@isDerived) or $attribute/@isDerived = "false") then "false" else "true"
        let $isDerivedUnion := if (not($attribute/@isDerivedUnion) or $attribute/@isDerivedUnion = "false") then "false" else "true"
        let $constness := if (starts-with($unqualifiedType, "QList") and $isDerived = "false") then "" else " const"
        where $attribute[not(@association)]
        return
        <attribute isDerived="{$isDerived}" isDerivedUnion="{$isDerivedUnion}">
        <accessor return="{$unqualifiedType}" name="{qtxmi:mappedFunctionName($attribute/@name)}" constness="{$constness}"/>
        {
        if (not(starts-with($unqualifiedType, "QList")) and ($attribute[not(@isReadOnly)] or $attribute/@isReadOnly != "true") and $isDerived = "false") then
        <accessor return="void " name="set{qtxmi:capitalizedNameFromTypeString($unqualifiedType, qtxmi:mappedFunctionName($attribute/@name))}" constness="">
           <parameter type="{$unqualifiedType}" name="{qtxmi:mappedFunctionName($attribute/@name)}"/>
        </accessor>
        else ""
        }
        {
        if ($attribute/ownedComment/body) then
        <documentation>{$attribute/ownedComment/body/text()}</documentation>
        else ""
        }
        </attribute>
        }
        {
        for $attribute in $class/ownedAttribute
        let $unqualifiedType := qtxmi:unqualifiedTypeFromNamespacedProperty($attribute, $namespace)
        let $unqualifiedType := if (ends-with($unqualifiedType, "*")) then $unqualifiedType else concat($unqualifiedType, " ")
        let $isDerived := if (not($attribute/@isDerived) or $attribute/@isDerived = "false") then "false" else "true"
        let $isDerivedUnion := if (not($attribute/@isDerivedUnion) or $attribute/@isDerivedUnion = "false") then "false" else "true"
        let $constness := if (starts-with($unqualifiedType, "QList") and $isDerived = "false") then "" else " const"
        where $attribute[@association]
        return
        <associationend isDerived="{$isDerived}" isDerivedUnion="{$isDerivedUnion}">
        <accessor return="{$unqualifiedType}" name="{qtxmi:mappedFunctionName($attribute/@name)}" constness="{$constness}"/>
        {
        if (not(starts-with($unqualifiedType, "QList")) and ($attribute[not(@isReadOnly)] or $attribute/@isReadOnly != "true") and $isDerived = "false") then
        <accessor return="void " name="set{qtxmi:capitalizedNameFromTypeString($unqualifiedType, qtxmi:mappedFunctionName($attribute/@name))}" constness="">
           <parameter type="{$unqualifiedType}" name="{qtxmi:mappedFunctionName($attribute/@name)}"/>
        </accessor>
        else ""
        }
        {
        if ($attribute/ownedComment/body) then
        <documentation>{$attribute/ownedComment/body/text()}</documentation>
        else ""
        }
        </associationend>
        }
        {
        for $operation in $class/ownedOperation
        let $constness := if ($operation/@isQuery = "true") then " const" else ""
        let $return := if ($operation/ownedParameter[@direction = "return"]) then
                          qtxmi:unqualifiedTypeFromNamespacedProperty($operation/ownedParameter[@direction = "return"], $namespace)
                       else "void"
        let $return := if (ends-with($return, "*")) then $return else concat($return, " ")
        return
        <operation return="{$return}" name="{qtxmi:mappedFunctionName($operation/@name)}" constness="{$constness}">
        {
        for $parameter in $operation/ownedParameter[not(@direction) or @direction != "return"]
        let $unqualifiedType := qtxmi:unqualifiedTypeFromNamespacedProperty($parameter, $namespace)
        let $unqualifiedType := if (ends-with($unqualifiedType, "*")) then $unqualifiedType else concat($unqualifiedType, " ")
        let $unqualifiedType := if (ends-with($unqualifiedType, "*") and (not($parameter/@direction) or $parameter/@direction = "in")) then concat("const ", $unqualifiedType) else $unqualifiedType
        return
            <parameter type="{$unqualifiedType}" name="{qtxmi:mappedFunctionName($parameter/@name)}"/>
        }
        {
        if ($operation/ownedComment/body) then
        <documentation>{$operation/ownedComment/body/text()}</documentation>
        else ""
        }
        </operation>
        }
    </class>
}
{
for $enumeration in doc($xmiFile)//packagedElement[@xmi:id=$namespace]/packagedElement[@xmi:type="uml:Enumeration"]
return
    <enumeration name="{$enumeration/@name}">
        {
        if ($enumeration/ownedComment/body) then
        <documentation>{$enumeration/ownedComment/body/text()}</documentation>
        else ""
        }
        {
        for $literal in $enumeration/ownedLiteral
        return
        <literal name="{concat(upper-case(substring($literal/@name, 1, 1)), substring($literal/@name, 2))}" documentation="{$literal/ownedComment/body/text()}"/>
        }
    </enumeration>
}
</namespace>
}
</qtxmi:XMI>