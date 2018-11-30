#pragma once
#include "common.h"
#include "Node.h"
#include "Element.h"
#include "Key.h"
#include "Object.h"


typedef struct _UnsortedLinkedDictionary UnsortedLinkedDictionary;

UnsortedLinkedDictionary* UnsortedLinkedDictionary_new(int maxSize);
void UnsortedLinkedDictionary_delete(UnsortedLinkedDictionary* _this);
Boolean UnsortedLinkedDictionary_isEmpty(UnsortedLinkedDictionary* _this);
Boolean UnsortedLinkedDictionary_isFull(UnsortedLinkedDictionary* _this);
void UnsortedLinkedDictionary_AddKeyAndObject(UnsortedLinkedDictionary* _this, Key* aKey, Object* object);
Boolean UnsortedLInkedDictionary_keyDoesExist(UnsortedLinkedDictionary* _this, Key* akey);
Element* UnsortedLinkedDictionary_removeObjectForKey(UnsortedLinkedDictionary* _this, Key* aKey);