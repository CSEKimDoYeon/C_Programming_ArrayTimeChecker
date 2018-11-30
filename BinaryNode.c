#include "BinaryNode.h"

struct  _BinaryNode
{
	Element* _element;
	BinaryNode* _left;
	BinaryNode* _right;
};

BinaryNode* BinaryNode_new() {
	BinaryNode* _this = NewObject(BinaryNode);
	_this->_element = NULL;
	_this->_left = NULL;
	_this->_right = NULL;
	return _this;
}
BinaryNode* BinaryNode_newWith(Element* _element, BinaryNode* aLeft, BinaryNode* aRight) {
	BinaryNode* _this = NewObject(BinaryNode);
	_this->_element = _element;
	_this->_left = aLeft;
	_this->_right = aRight;
	return _this;
}
void BinaryNode_delete(BinaryNode* _this) {
	Element_delete(_this->_element);
	free(_this->_left);
	free(_this->_right);
	free(_this);
	
}
/*void BInaryNode_setKey(BinaryNode* _this, Key* aKey) {
	_this->_key = aKey;
}*/

Key* BinaryNode_key(BinaryNode* _this) {
	return Element_getKey(_this->_element);
}

/*void BinaryNode_setObject(BinaryNode* _this, Object* anObject) {
	_this->_object = anObject;
}
Object* BinaryNode_object(BinaryNode* _this) {
	return _this->_object;
}*/

void BinaryNode_setElement(BinaryNode* _this, Element* _element) {
	_this->_element = _element;
}
Element* BinaryNode_Element(BinaryNode* _this) {
	return _this->_element;
}

void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aLeft) {
	_this->_left = aLeft;
}

BinaryNode* BinaryNode_left(BinaryNode* _this) {
	return _this->_left;
}
void BinaryNode_setright(BinaryNode* _this, BinaryNode* aRight) {
	_this->_right = aRight;
}
BinaryNode* BinaryNode_right(BinaryNode* _this) {
	return _this->_right;
}