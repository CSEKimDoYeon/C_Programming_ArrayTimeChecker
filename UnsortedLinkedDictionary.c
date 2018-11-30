#include "UnsortedLinkedDictionary.h"

struct _UnsortedLinkedDictionary {
	Node* _element;
	int _size;
	int _capacity;
};

void UnsortedLinkedDictionary_deleteLInkedChain(UnsortedLinkedDictionary* _this);

UnsortedLinkedDictionary* UnsortedLinkedDictionary_new(int maxSize) {
	UnsortedLinkedDictionary* _this = NewObject(UnsortedLinkedDictionary);
	_this->_element = Node_new();
	_this->_size = 0;
	_this->_capacity = maxSize;
	return _this;
}
void UnsortedLinkedDictionary_delete(UnsortedLinkedDictionary* _this) {
	UnsortedLinkedDictionary_deleteLInkedChain(_this);
	free(_this);
}
Boolean UnsortedLinkedDictionary_isEmpty(UnsortedLinkedDictionary* _this) {
	return _this->_size == 0;
}
Boolean UnsortedLinkedDictionary_isFull(UnsortedLinkedDictionary* _this) {
	return _this->_size == _this->_capacity;
}
void UnsortedLinkedDictionary_AddKeyAndObject(UnsortedLinkedDictionary* _this, Key* aKey, Object* object) {
	if (UnsortedLinkedDictionary_isFull(_this)) {
		return;
	}
	else {
		Element* add = Element_new();
		Element_setKey(add, aKey);
		Element_setObject(add, object);
		if (UnsortedLinkedDictionary_isEmpty(_this)) {
			Node_setElement(_this->_element, add);
			_this->_size++;
		}
		else {
			Node* addNode = Node_new();
			Node_setElement(addNode, add);
			Node_setNext(addNode, _this->_element);
			_this->_element = addNode;
			_this->_size++;
		}
	}

}
Boolean UnsortedLInkedDictionary_keyDoesExist(UnsortedLinkedDictionary* _this, Key* akey) {
	Node* currentNode = _this->_element;
	while (currentNode != NULL) {
		Element* currntElement = Node_element(currentNode);
		if (Key_compareTo(Element_getKey(currntElement), akey) == 0) {
			return TRUE;
		}
		currentNode = Node_next(currentNode);
	}
	return FALSE;
}
Element* UnsortedLinkedDictionary_removeObjectForKey(UnsortedLinkedDictionary* _this, Key* aKey) {
	
	if (UnsortedLinkedDictionary_isEmpty(_this)) {
		return;
	}
	else {
		Node* currentNode = _this->_element;
		if (_this->_size == 1) {
			if (Key_compareTo(Element_getKey(Node_element(_this->_element)), aKey) == 0) {
				Node* removeNode = _this->_element;
				Node_delete(_this->_element);
				return Node_element(removeNode);
			}
			else return;
		}
		else {
			Node* currentNode = _this->_element;
			while (Node_next(currentNode) != NULL) {
				Element* NextElement = Node_element(Node_next(currentNode));
				if (Key_compareTo(Element_getKey(NextElement), aKey) == 0) {
					Node* removeNode = Node_next(currentNode);
					Node_setNext(currentNode, Node_next(Node_next(currentNode)));
					Element* removeElement= Node_element(removeNode);
					Node_delete(removeNode);
					return removeElement;
				}
				currentNode = Node_next(currentNode);
			}
			return;
		}
		
	}
	
}

void UnsortedLinkedDictionary_deleteLInkedChain(UnsortedLinkedDictionary* _this) {
	Node* currentNode = _this->_element;
	Node* NodeToBeDelete;
	while (currentNode != NULL) {
		NodeToBeDelete = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(NodeToBeDelete);
	}
}