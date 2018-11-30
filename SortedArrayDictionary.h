#pragma once
#include "common.h"
#include "Element.h"
#include "Key.h"
#include "Object.h"

typedef struct _SortedArrayDictionary SortredArrayDictionary;

SortredArrayDictionary* SortedArrayDictionary_new(int maxSize);
void SortedArrayDictionary_delete(SortredArrayDictionary* _this);
Boolean SortedArrayDictionary_isEmpty(SortredArrayDictionary* _this);
Boolean SortedArrayDictionary_isFull(SortredArrayDictionary* _this);
void SortedArrayDictionary_addKeyAndObject(SortredArrayDictionary* _this, Key* aKey, Object* anObject);
Boolean SortedArrayDictionary_KeyDoesExist(SortredArrayDictionary* _this, Key* aKey);
Element* SortedArrayDictionary_removeObjectForKey(SortredArrayDictionary* _this, Key* aKey);
