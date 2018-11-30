#pragma once
#include "common.h"
#include "Element.h"
#include "Key.h"
#include "Object.h"


typedef struct _BinaryNode BinaryNode;

BinaryNode* BinaryNode_new();
BinaryNode* BinaryNode_newWith(Element* _element, BinaryNode* aLeft, BinaryNode* aRight);
void BinaryNode_delete(BinaryNode* _this);
//void BInaryNode_setKey(BinaryNode* _this, Key* aKey);
Key* BinaryNode_key(BinaryNode* _this);
//void BinaryNode_setObject(BinaryNode* _this, Object* anObject);
//Object* BinaryNode_object(BinaryNode* _this);*/

void BinaryNode_setElement(BinaryNode* _this, Element* _element);
Element* BinaryNode_Element(BinaryNode* _this);
void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aLeft);
BinaryNode* BinaryNode_left(BinaryNode* _this);
void BinaryNode_setright(BinaryNode* _this, BinaryNode* aRight);
BinaryNode* BinaryNode_right(BinaryNode* _this);