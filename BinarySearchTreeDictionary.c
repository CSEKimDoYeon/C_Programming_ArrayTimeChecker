#include "BinarySearchTreeDictionary.h"

struct _BinarySearchTreeDictionary
{
	BinaryNode* _root;
	int _size;
	int _capacity;
};

Boolean BinarySearchTreeDictionary_addToTree(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent);
Boolean BInarySearchTreeDictionary_SearchTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* aNode);
Element* BinarySearchTreeDicitonary_removeFromTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* parent);
BinaryNode* BInarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(BinarySearchTreeDictionary* _this, BinaryNode* aNode);

BinarySearchTreeDictionary* BinarySearchTreeDictionary_new() {
	BinarySearchTreeDictionary* _this = NewObject(BinarySearchTreeDictionary);
	_this->_root = NULL;
	_this->_size = 0;
	
	return _this;
}
void BinarySearchTreeDictionary_delete(BinarySearchTreeDictionary* _this) {
	free(_this);
}
Boolean BinarySearchTreeDictionary_isEmpty(BinarySearchTreeDictionary* _this) {
	return _this->_size == 0;
}
Boolean BinarySearchTreeDictionary_isFull(BinarySearchTreeDictionary* _this) {
	return FALSE;
}
void BinarySearchTreeDictionary_addKeyAndObject(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject) {
	if (BinarySearchTreeDictionary_isFull(_this)) {
		return;
	}
	else {
		if (_this->_root == NULL) {
			BinaryNode* addNode = BinaryNode_newWith(Element_newWith(aKey, anObject), NULL, NULL);
			_this->_root = addNode;
			_this->_size++;
		}
		else { 
			_this->_size++;
			BinarySearchTreeDictionary_addToTree(_this, aKey, anObject, _this->_root);
		}
	}
}

Boolean BinarySearchTreeDictionary_addToTree(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent) {
	if (Key_compareTo(aKey, Element_getKey(BinaryNode_Element(parent))) <0) {
		if (BinaryNode_left(parent) == NULL) {
			BinaryNode_setLeft(parent, BinaryNode_newWith(Element_newWith(aKey, anObject), NULL, NULL));
			return TRUE;
		}
		else {
			return BinarySearchTreeDictionary_addToTree(_this, aKey, anObject, BinaryNode_left(parent));
		}
	}
	else if (Key_compareTo(aKey, Element_getKey(BinaryNode_Element(parent))) > 0) {
		if (BinaryNode_right(parent) == NULL) {
			BinaryNode_setright(parent, BinaryNode_newWith(Element_newWith(aKey, anObject), NULL, NULL));
			return TRUE;
		}
		else {
			return BinarySearchTreeDictionary_addToTree(_this, aKey, anObject, BinaryNode_right(parent));
		}
	}
	else {
		return FALSE;
	}
}

Boolean BinarySearchTreeDictionary_KeyDoesExist(BinarySearchTreeDictionary* _this, Key* aKey) {
	return BInarySearchTreeDictionary_SearchTreeRecursively(_this, aKey, _this->_root);
}

Boolean BInarySearchTreeDictionary_SearchTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* aNode) {
	if (aNode == NULL) {
		return FALSE;
	}
	else {
		if (Key_compareTo(aKey, Element_getKey(BinaryNode_Element(aNode))) == 0) {
			return TRUE;
		}
		else if (Key_compareTo(aKey, Element_getKey(BinaryNode_Element(aNode))) < 0) {
			return BInarySearchTreeDictionary_SearchTreeRecursively(_this, aKey, BinaryNode_left(aNode));
		}
		else if (Key_compareTo(aKey, Element_getKey(BinaryNode_Element(aNode))) > 0) {
			return BInarySearchTreeDictionary_SearchTreeRecursively(_this, aKey, BinaryNode_right(aNode));
		}
	}
}
Element* BinarySearchTreeDictionary_removeObjectForKey(BinarySearchTreeDictionary* _this, Key* aKey) {
	if (BinarySearchTreeDictionary_isEmpty(_this)) {
		return NULL;
	}
	else {
		if (Key_compareTo(aKey,BinaryNode_key(_this->_root)) != 0) {
			return BinarySearchTreeDicitonary_removeFromTreeRecursively(_this, aKey, _this->_root);
		}
		else {
			BinaryNode* removeNOde = _this->_root;
			if (BinaryNode_left(_this->_root) == NULL) {
				_this->_root = BinaryNode_right(_this->_root);
			}
			else if (BinaryNode_right(_this->_root) == NULL) {
				_this->_root = BinaryNode_left(_this->_root);
			}
			else {
				BinaryNode* rightmost = BInarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(_this, removeNOde);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removeNOde));
				BinaryNode_setright(rightmost, BinaryNode_right(removeNOde));
				_this->_root = rightmost;
			}
			Element* removeElement = BinaryNode_Element(removeNOde);
			BinaryNode_setElement(removeNOde, NULL);

			BinaryNode_setLeft(removeNOde, NULL);
			BinaryNode_setright(removeNOde, NULL);
			BinaryNode_delete(removeNOde);
			_this->_size--;
			return removeElement;
		}
	}
}

Element* BinarySearchTreeDicitonary_removeFromTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* parent) {
	if (Key_compareTo(aKey, Element_getKey(BinaryNode_Element(parent))) < 0) {
		BinaryNode* leftchild = BinaryNode_left(parent);
		if (leftchild == NULL) {
			return NULL;
		}
	    if (Key_compareTo(aKey, BinaryNode_key(leftchild)) == 0) {
			BinaryNode* removeNode = leftchild;

			if(BinaryNode_left(removeNode) == NULL){
				BinaryNode_setLeft(parent, BinaryNode_right(removeNode));
			}
			else if(BinaryNode_right(removeNode)== NULL)
			{
				BinaryNode_setLeft(parent, BinaryNode_left(removeNode));
			}
			else {
				BinaryNode* rightmost = BInarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(_this,removeNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removeNode));
				BinaryNode_setright(rightmost, BinaryNode_right(removeNode));
				BinaryNode_setLeft(parent, rightmost);
			}
			Element* removeElement = BinaryNode_Element(removeNode);
			BinaryNode_setElement(removeNode, NULL);
			BinaryNode_setLeft(removeNode, NULL);
			BinaryNode_setright(removeNode, NULL);
			BinaryNode_delete(removeNode);
			_this->_size--;
			return removeElement;
		}
		else {
			return BinarySearchTreeDicitonary_removeFromTreeRecursively(_this, aKey, leftchild);
		}
	}
	else {
		BinaryNode* rightChiild = BinaryNode_right(parent);
		if (rightChiild == NULL) {
			return NULL;
		}
	 if (Key_compareTo(aKey, BinaryNode_key(rightChiild)) == 0){
			BinaryNode* removeNode = rightChiild;
	
			if (BinaryNode_left(removeNode) == NULL) {
				BinaryNode_setright(parent, BinaryNode_right(removeNode));
			}
			else if (BinaryNode_right(removeNode) == NULL) {
				BinaryNode_setright(parent, BinaryNode_left(removeNode));
			}
			else{
				BinaryNode* rightmost = BInarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(_this, removeNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removeNode));
				BinaryNode_setright(rightmost, BinaryNode_right(removeNode));
				BinaryNode_setright(parent, rightmost);
			}
			Element* removeElement = BinaryNode_Element(removeNode);
			BinaryNode_setElement(removeNode, NULL);

			BinaryNode_setLeft(removeNode, NULL);
			BinaryNode_setright(removeNode, NULL);
			BinaryNode_delete(removeNode);
			_this->_size--;
			return removeElement;
		}
		else {
			return BinarySearchTreeDicitonary_removeFromTreeRecursively(_this, aKey, rightChiild);
		}
	}
}
BinaryNode* BInarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(BinarySearchTreeDictionary* _this, BinaryNode* aNode) {
	BinaryNode* rightmost = NULL;
	BinaryNode* leftOfRoot = BinaryNode_left(aNode);
	rightmost = leftOfRoot;
	if (BinaryNode_right(leftOfRoot) == NULL) {
		BinaryNode_setLeft(aNode, BinaryNode_left(leftOfRoot));
	}
	else {
		BinaryNode* parentOfRightmost = NULL;
		do {
			parentOfRightmost = rightmost;
			rightmost = BinaryNode_right(rightmost);
		} while (BinaryNode_right(rightmost) != NULL);
		BinaryNode_setright(parentOfRightmost, BinaryNode_left(rightmost));
	}
	BinaryNode_setLeft(rightmost, NULL);
	BinaryNode_setright(rightmost, NULL);
	return rightmost;
}