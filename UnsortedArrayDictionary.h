#pragma once
#include "common.h"
#include "Element.h"
#include "Key.h"
#include "Object.h"

typedef struct _UnsortedArrayDictionary UnsortedArrayDictionary;

UnsortedArrayDictionary* UnsortedArrayDictionary_new(int maxSize);
void UnsortedArrayDictionary_delete(UnsortedArrayDictionary* _this);
Boolean UnsortedArrayDictionary_isEmpty(UnsortedArrayDictionary* _this);
Boolean UnsortedArrayDictionary_isFull(UnsortedArrayDictionary* _this);
void UnsortedArrayDictionary_AddKeyAndObject(UnsortedArrayDictionary* _this, Key* aKey, Object* anObject);
Boolean UnsortedArrayDictionary_keyDoesExist(UnsortedArrayDictionary* _this, Key* aKey);
Element* UnsortedArrayDictionary_removeObjectForKey(UnsortedArrayDictionary* _this, Key* aKey);