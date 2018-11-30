#pragma once
#include "common.h"
#include "Key.h"
#include "Object.h"

typedef struct _Element Element;

Element* Element_new();
Element* Element_newWith(Key* akey, Object* anObject);
void Element_delete(Element* _this);
void Element_setKey(Element* _this, Key* aKey);
void Element_setObject(Element* _this, Object* object);
Key* Element_getKey(Element* _this);
Object* Element_getObject(Element* _this);