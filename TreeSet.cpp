
#include "TreeSet.h"

TreeSet::TreeSet()
{
	this->root = NULL;
	this->count = 0;
}


TreeSet::~TreeSet()
{
	clear();
}

void TreeSet::clearRec(AVLNode* root) {
	if (root != NULL) {
		clearRec(root->left);
		clearRec(root->right);
		delete root;
	}
}
void TreeSet::clear() {
	clearRec(this->root);
	this->root = NULL;
	this->count = 0;
}

// add a element with given value
// return 1 if success, otherwise
int TreeSet::add(int val) {
	// TODO
	bool taller = false;
	bool check = contains(val);
	if (check) {
		return 0;
	}
	this->root = recAdd(this->root, val, taller);
	return 1;

}
AVLNode* TreeSet::recAdd(AVLNode* root, int val, bool taller) {
	// TODO
	// insert root
	if (root == NULL) {
		root = new AVLNode(val);
		taller = true;
		count++;
		return root;
	}
	if (val < root->key) {
		root->left = recAdd(root->left, val, taller);
		// left subtree is taller
		if (taller) {
			if (root->balance == -1) {
				root = leftBalance(root, taller);
			}
			else if (root->balance == 0) {
				root->balance = -1;
			}
			else {
				root->balance = 0;
				taller = false;
			}
		}
	}
	else {
		root->right = recAdd(root->right, val, taller);
		// right subtree is taller
		if (taller) {
			if (root->balance == -1) {
				root->balance = 0;
				taller = false;
			}
			else if (root->balance == 0) {
				root->balance = 1;
			}
			else {
				root = rightBalance(root, taller);
			}
		}
	}
	return root;
}
AVLNode* TreeSet::leftBalance(AVLNode* root, bool taller) {
	AVLNode* leftTree = root->left;
	if (leftTree != NULL) {
		// Left of left
		if (leftTree->balance == -1) {
			rotateRight(root);
			root->balance = 0;
			leftTree->balance = 0;
			taller = false;
		}
		// Right of left
		else {
			AVLNode* rightTree = leftTree->right;
			if (rightTree != NULL) {
				if (rightTree->balance == -1) {
					root->balance = 1;
					leftTree->balance = 0;
				}
				else if (rightTree->balance == 0) {
					leftTree->balance = 0;
				}
				else {
					root->balance = 0;
					leftTree->balance = -1;
				}
				rightTree->balance = 0;
				root->left = rotateLeft(leftTree);
				root = rotateRight(root);
				taller = false;
			}
		}
	}
	return root;
}
AVLNode* TreeSet::rightBalance(AVLNode* root, bool taller) {
	AVLNode* rightTree = root->right;
	if (rightTree != NULL) {
		// Right of right
		if (rightTree->balance == 1) {
			rotateLeft(root);
			root->balance = 0;
			rightTree->balance = 0;
			taller = false;
		}
		// Left of right
		else {
			AVLNode* leftTree = rightTree->right;
			if (leftTree != NULL) {
				if (leftTree->balance == 1) {
					root->balance = -1;
					rightTree->balance = 0;
				}
				else if (leftTree->balance == 0) {
					rightTree->balance = 0;
				}
				else {
					root->balance = 0;
					rightTree->balance = 1;
				}
				leftTree->balance = 0;
				root->right = rotateRight(rightTree);
				root = rotateLeft(root);
				taller = false;
			}
		}
	}
	return root;
}
AVLNode* TreeSet::rotateLeft(AVLNode* root) {
	AVLNode*tempPtr = root->right;
	root->right = tempPtr->left;
	tempPtr->left = root;
	return tempPtr;
}
AVLNode* TreeSet::rotateRight(AVLNode* root) {
	AVLNode* tempPtr = root->left;
	root->left = tempPtr->right;
	tempPtr->right = root;
	return tempPtr;
}

bool TreeSet::contains(int val) {
	// TODO
	AVLNode* ret = recContains(this->root, val);
	if (ret == NULL) {
		return false;
	}
	return true;
}
AVLNode* TreeSet::recContains(AVLNode* root, int val) {
	// TODO
	if (root == NULL) {
		return NULL;
	}
	if (val < root->key) {
		return recContains(root->left, val);
	}
	else if (val > root->key) {
		return recContains(root->right, val);
	}
	else return root;
}

void TreeSet::copy(const TreeSet& set) {
	/*int* arr = set.toArray();
	for (int i = 0; i <set.size(); i++) {
		add(arr[i]);
	}*/
	AVLNode* current = set.root;
	while (current !=NULL)
	{
		this->add(current->key);
		if (current->left!=NULL)
		{
			current = current->left;
			continue;
		}
		if (current->right!=NULL)
		{
			current = current->right;
			continue;
		}
	}
}

int TreeSet::first() {
	// TODO
	AVLNode* ret = recFirst(this->root);

	return ret->key;
}
AVLNode* TreeSet::recFirst(AVLNode* root) {
	if (root == NULL) {
		throw "NoSuchElementException";
	}
	// TODO
	if (root->left == NULL) {
		return root;
	}
	return recFirst(root->left);
}

int TreeSet::last() {
	// TODO
	AVLNode* ret = recLast(this->root);

	return ret->key;
}
AVLNode* TreeSet::recLast(AVLNode* root) {
	if (root == NULL) {
		throw "NoSuchElementException";
	}

	// TODO
	if (root->right == NULL) {
		return root;
	}
	return recLast(root->right);
}

int TreeSet::higher(int val) {
	
	int result = -1;
	AVLNode *current = root;
	if (this->contains(val))
	{
		return -1;
	}
	while (current != NULL) {
		if (val < current->key) {
			result = current->key;
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	return result;
}

int TreeSet::lower(int val) {
	
	int result = -1;
	AVLNode *current = root;
	if (this->contains(val))
	{
		return -1;
	}
	while (current != NULL) {
		
		if (val > current->key) {
			result = current->key;
			current = current->right;
		}
		else {
			 current = current->left;

		}
	}
	return result;
}

AVLNode *TreeSet::removeNode(AVLNode* &root, int val, bool shorter, bool success) {
	if (root == NULL) {
		shorter = false;
		success = false;
		return NULL;
	}
	if (val < root->key) {
		root->left = removeNode(root->left, val, shorter, success);
		if (shorter) {
			root = deleteRightBalance(root, shorter);
		}
	}
	else if (val > root->key) {
		root->right = removeNode(root->right, val, shorter, success);
		if (shorter) {
			root = deleteLeftBalance(root, shorter);
		}
	}
	else {
		AVLNode * deleteNode = root;
		if (root->right == NULL) {
			AVLNode* newRoot = root->left;
			success = true;
			shorter = true;
			delete deleteNode;
			return newRoot;
		}
		else if (root->left == NULL) {
			AVLNode* newRoot = root->right;
			success = true;
			shorter = true;
			delete deleteNode;
			return newRoot;
		}
		else {
			AVLNode* exchPtr = root->left;
			while (exchPtr->right != NULL) {
				exchPtr = exchPtr->right;
			}
			root->key = exchPtr->key;
			root->left = removeNode(root->left, exchPtr->key, shorter, success);

			if (shorter) {
				root = deleteRightBalance(root, shorter);
			}
		}
	}
	return root;
}
AVLNode *TreeSet::deleteRightBalance(AVLNode* root, bool shorter) {
	if (root->balance == -1) {
		root->balance = 0;
	}
	else if (root->balance == 0) {
		root->balance = 1;
		shorter = false;
	}
	else {
		AVLNode* rightTree = root->right;
		if (rightTree != NULL) {
			if (rightTree->balance == -1) {
				AVLNode * leftTree = rightTree->left;
				if (leftTree->balance == -1) {
					rightTree->balance = 1;
					root->balance = 0;
				}
				else if (leftTree->balance == 0) {
					root->balance = -1;
					rightTree->balance = 0;
				}
				else {
					root->balance = -1;
					rightTree->balance = 0;
				}
				leftTree->balance = 0;
				root->right = rotateRight(rightTree);
				root = rotateLeft(root);
			}
			else {
				if (rightTree->balance != 0) {
					root->balance = 0;
					rightTree->balance = 0;
				}
				else {
					root->balance = 1;
					rightTree->balance = -1;
					shorter = false;
				}
				root = rotateLeft(root);
			}
		}
	}
	return root;
}
AVLNode *TreeSet::deleteLeftBalance(AVLNode* root, bool shorter) {
	if (root->balance == 1) {
		root->balance = 0;
	}
	else if (root->balance == 0) {
		root->balance = -1;
		shorter = false;
	}
	else {
		AVLNode* leftTree = root->left;
		if (leftTree != NULL) {
			if (leftTree->balance == 1) {
				AVLNode * rightTree = leftTree->right;
				if (rightTree->balance == 1) {
					leftTree->balance = -1;
					root->balance = 0;
				}
				else if (rightTree->balance == 0) {
					root->balance = 1;
					leftTree->balance = 0;
				}
				else {
					root->balance = 1;
					leftTree->balance = 0;
				}
				rightTree->balance = 0;
				root->left = rotateLeft(leftTree);
				root = rotateRight(root);
			}
			else {
				if (leftTree->balance != 0) {
					root->balance = 0;
					leftTree->balance = 0;
				}
				else {
					root->balance = -1;
					leftTree->balance = 1;
					shorter = false;
				}
				root = rotateRight(root);
			}
		}
	}
	return root;
}

int TreeSet::remove(int val) {
	// TODO
	bool shorter=false;
	bool success = false;
	AVLNode* ret = removeNode(this->root, val, shorter, success);
	if (success) {
		return 1;
	}
/*
	return removeNode(this->root, val, shorter, bool success);*/
	return 0;

}


TreeSet* TreeSet::subSet(int fromVal, int toVal) {
	// TODO
	//return NULL;
	TreeSet *result = new TreeSet();
	int* arr=this->toArray();
	for (int i = 0; i < this->size(); i++)
	{
		if (arr[i] > fromVal&&arr[i] < toVal) {
			result->add(arr[i]);
		}
	}
	return result;
}

int TreeSet::size() {
	// TODO
	return this->count;

}

int* TreeSet::toArray() {
	int* ret = new int(count);
	recToArray(root, ret, 0);
	return ret;
	//return NULL;
}
void TreeSet::recToArray(AVLNode* root, int values[], int index) {
	if (root == NULL) {
		return;
	}
	if (root->left != NULL) {
		recToArray(root->left, values, index);
	}
	values[index] = root->key;
	index++;
	if (root->right != NULL) {
		recToArray(root->right, values, index);
	}
}