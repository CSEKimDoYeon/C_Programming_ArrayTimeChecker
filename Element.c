#include "Element.h"



struct _Element
{
	Key* _key;
	Object* _object;
};

Element* Element_new() {
	Element* _this = NewObject(Element);
	_this->_key = NULL;
	_this->_object = NULL;
	return _this;
}

Element* Element_newWith(Key* aKey, Object* anObject) {
	Element* _this = NewObject(Element);
	_this->_key = aKey;
	_this->_object = anObject;
	return _this;
}

void Element_delete(Element* _this) {
	free(_this);
}
void Element_setKey(Element* _this, Key* aKey) {
	_this->_key = aKey;
}
void Element_setObject(Element* _this, Object* object) {
	_this->_object = object;
}
Key* Element_getKey(Element* _this) {
	return _this->_key;
}
Object* Element_getObject(Element* _this) {
	return _this->_object;
}