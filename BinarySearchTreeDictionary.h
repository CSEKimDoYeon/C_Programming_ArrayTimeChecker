#pragma once
#include "common.h"
#include "BinaryNode.h"
#include "Element.h"
#include "Key.h"
#include "Object.h"

typedef struct _BinarySearchTreeDictionary BinarySearchTreeDictionary;

BinarySearchTreeDictionary* BinarySearchTreeDictionary_new();
void BinarySearchTreeDictionary_delete(BinarySearchTreeDictionary* _this);
Boolean BinarySearchTreeDictionary_isEmpty(BinarySearchTreeDictionary* _this);
Boolean BinarySearchTreeDictionary_isFull(BinarySearchTreeDictionary* _this);
void BinarySearchTreeDictionary_addKeyAndObject(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject);
Boolean BinarySearchTreeDictionary_KeyDoesExist(BinarySearchTreeDictionary* _this, Key* aKey);
Element* BinarySearchTreeDictionary_removeObjectForKey(BinarySearchTreeDictionary* _this, Key* aKey);