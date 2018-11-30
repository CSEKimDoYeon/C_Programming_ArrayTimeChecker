#include "SortedArrayDictionary.h"

struct _SortedArrayDictionary
{
	Element** _element;
	int _size;
	int _capacity;

};

SortredArrayDictionary* SortedArrayDictionary_new(int maxSize) {
	SortredArrayDictionary* _this = NewObject(SortredArrayDictionary);
	_this->_size = 0;
	_this->_capacity = maxSize;
	_this->_element = NewVector(Element*, maxSize);
	return _this;
}
void SortedArrayDictionary_delete(SortredArrayDictionary* _this) {
	free(_this->_element);
	free(_this);
}
Boolean SortedArrayDictionary_isEmpty(SortredArrayDictionary* _this) {
	return _this->_size == 0;
}
Boolean SortedArrayDictionary_isFull(SortredArrayDictionary* _this) {
	return _this->_size == _this->_capacity;
}
void SortedArrayDictionary_addKeyAndObject(SortredArrayDictionary* _this, Key* aKey, Object* anObject) {

	if (SortedArrayDictionary_isFull(_this)) {
		return;
	}
	else {
		Element* add = Element_new();
		Element_setKey(add, aKey);
		Element_setObject(add, anObject);
		if (_this->_size == 0) {
			_this->_element[_this->_size] = add;
			_this->_size++;
		}
		else {
			int i = 0;
			while (i < _this->_size) {
					if (Key_compareTo(Element_getKey(_this->_element[i]),aKey) == 1) {
						break;
					}
					i++;
			}
			for (int x = _this->_size; x > i; x--) {
				_this->_element[x] = _this->_element[x-1];
			}
			_this->_element[i] = add;
			_this->_size++;
		}
	}
}
Boolean SortedArrayDictionary_KeyDoesExist(SortredArrayDictionary* _this, Key* aKey) {
	for (int i = 0; i < _this->_size; i++) {
		if (Key_compareTo(Element_getKey(_this->_element[i]), aKey) == 0)
			return TRUE;
	}
	return FALSE;
}
Element* SortedArrayDictionary_removeObjectForKey(SortredArrayDictionary* _this, Key* aKey) {
	Element* removeElement;
	for (int i = 0; i < _this->_size; i++) {
		if (Key_compareTo(Element_getKey(_this->_element[i]), aKey) == 0) {
			removeElement = _this->_element[i];
			while (i < _this->_size) {
				_this->_element[i] = _this->_element[++i];
			}
			return removeElement;
		}
	}
}
