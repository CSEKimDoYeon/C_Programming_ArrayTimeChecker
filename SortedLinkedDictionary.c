#include "SortedLinkedDictionary.h"

struct _SortedLinkedDictionary {
	Node* _element;
	int _size;
	int _capacity;
};

void SortedLinkedDictionary_deleteLInkedChain(SortedLinkedDictionary* _this);

SortedLinkedDictionary* SortedLinkedDictionary_new(int maxsize) {
	SortedLinkedDictionary* _this = NewObject(SortedLinkedDictionary);
	_this->_element = Node_new();
	_this->_size = 0;
	_this->_capacity = maxsize;
	return _this;
}
void SortedLinkedDictionary_delete(SortedLinkedDictionary* _this) {
	SortedLinkedDictionary_deleteLInkedChain(_this);
	free(_this);

}
Boolean SortedLinkedDictionary_isEmpty(SortedLinkedDictionary* _this) {
	return _this->_size == 0;
}
Boolean SortedLinkedDictionary_isFull(SortedLinkedDictionary* _this) {
	return _this->_size == _this->_capacity;
}
void SortedLinkedDictionary_addKeyAndObject(SortedLinkedDictionary* _this, Key* aKey, Object* anObject) {
	if (SortedLinkedDictionary_isFull(_this)) {
		return;
	}
	else {
		Element* add = Element_new();
		Element_setKey(add, aKey);
		Element_setObject(add, anObject);
		if (SortedLinkedDictionary_isEmpty(_this)) {
			Node_setElement(_this->_element, add);
			_this->_size++;
		}
		else if (_this->_size == 1) {
			if (Key_compareTo(Element_getKey(Node_element(_this->_element)), aKey) == -1) {
				Node* addNode = Node_new();
				Node_setElement(addNode, add);
				Node_setNext(_this->_element, addNode);
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
		else {
			Node* addNode = Node_new();
			Node_setElement(addNode, add);
			Node* currentNode = _this->_element;
			
			while (Node_next(currentNode) != NULL) {
				Element* NextElement = Node_element(Node_next(currentNode));
				if (Key_compareTo(Element_getKey(NextElement), aKey) == 1) {
					Node_setNext(addNode, Node_next(currentNode));
					Node_setNext(currentNode, addNode);
					_this->_size++;
					return;
				}
				currentNode = Node_next(currentNode);
			}
		}
	}
}
Boolean SortedLinkedDictionary_KeyDoesExist(SortedLinkedDictionary* _this, Key* aKey) {
	Node* currentNode = _this->_element;
	while (currentNode != NULL) {
		Element* currntElement = Node_element(currentNode);
		if (Key_compareTo(Element_getKey(currntElement), aKey) == 0) {
			return TRUE;
		}
		currentNode = Node_next(currentNode);
	}
	return FALSE;
}
Element* SortedLinkedDictionary_removeObjectForKey(SortedLinkedDictionary* _this, Key* aKey) {
	if (SortedLinkedDictionary_isEmpty(_this)) {
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
					Element* removeElement = Node_element(removeNode);
					Node_delete(removeNode);
					return removeElement;
				}
				currentNode = Node_next(currentNode);
			}
			return;
		}

	}
}

void SortedLinkedDictionary_deleteLInkedChain(SortedLinkedDictionary* _this) {
	Node* currentNode = _this->_element;
	Node* NodeToBeDelete;
	while (currentNode != NULL) {
		NodeToBeDelete = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(NodeToBeDelete);
	}
}