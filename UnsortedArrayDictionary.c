#include "UnsortedArrayDictionary.h"

struct _UnsortedArrayDictionary
{
	Element** _element;
	int _size;
	int _capacity;
};

UnsortedArrayDictionary* UnsortedArrayDictionary_new(int maxSize) {
	UnsortedArrayDictionary* _this = NewObject(UnsortedArrayDictionary);
	_this->_size = 0;
	_this->_capacity = maxSize;
	_this->_element = NewVector(Element*, maxSize);
	return _this;
}
void UnsortedArrayDictionary_delete(UnsortedArrayDictionary* _this) {
	free(_this);
}
Boolean UnsortedArrayDictionary_isEmpty(UnsortedArrayDictionary* _this) {
	return _this->_size == 0;
}
Boolean UnsortedArrayDictionary_isFull(UnsortedArrayDictionary* _this) {
	return _this->_size == _this->_capacity;
}
void UnsortedArrayDictionary_AddKeyAndObject(UnsortedArrayDictionary* _this, Key* aKey, Object* anObject) {
	if (UnsortedArrayDictionary_isFull(_this)) {
		return;
	}
	else {
		Element* add = Element_new();
		Element_setKey(add, aKey);
		Element_setObject(add, anObject);
		_this->_element[_this->_size] = add;
		_this->_size++;
	}
}
Boolean UnsortedArrayDictionary_keyDoesExist(UnsortedArrayDictionary* _this, Key* aKey) {
	for (int i = 0; i < _this->_size; i++) {
		if (Key_compareTo(Element_getKey(_this->_element[i]),aKey) == 0)
			return TRUE;
	}
	return FALSE;
}
Element* UnsortedArrayDictionary_removeObjectForKey(UnsortedArrayDictionary* _this, Key* aKey) {
	Element* removeElement;
	for (int i = 0; i < _this->_size; i++) {
		if (Key_compareTo(Element_getKey(_this->_element[i]),aKey) == 0) {
			removeElement = _this->_element[i];
			//Element_delete(_this->_element[i]);
			while (i < _this->_size) {
				_this->_element[i] = _this->_element[++i];
			}
			return removeElement;
		}
	}
}