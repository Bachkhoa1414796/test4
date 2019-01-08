
#pragma once
#include"AVLNode.h"

class TreeSet
{
private:
	AVLNode * root = NULL;
	int count = 0;

protected:
	// recursive clear AVL tree
	void clearRec(AVLNode*root);

public:
	//initial AVL tree
	TreeSet();
	//destroy AVL tree
	~TreeSet();
	//delete AVL tree
	void clear();
	// print out the set in ascending order
	friend ostream& operator<<(ostream& os, const TreeSet& t);

	// YOUR TASKS START HERE	
	// add a val into AVL tree
	int add(int val);
	// return true if val has been in tree, else return false
	bool contains(int val);
	// recursive of contains()
	AVLNode* recContains(AVLNode* root, int val);
	// copy set tree to root
	void copy(const TreeSet& set);
	// get first value
	int first();
	// recursive of first()
	AVLNode* recFirst(AVLNode* root);
	// get value higher than val
	int higher(int val);
	// get last value
	int last();
	// recursive of last()
	AVLNode* recLast(AVLNode* root);
	// get value lower than val
	int lower(int val);
	// return 1 if remove(val) sucsess, else return 0
	int remove(int val);
	// remove a node
	AVLNode* removeNode(AVLNode* &root, int val, bool shorter, bool success);
	// delete left(right) node to make balance
	AVLNode* deleteRightBalance(AVLNode* root, bool shorter);
	AVLNode* deleteLeftBalance(AVLNode* root, bool shorter);
	// get subTree from fromVal to toVal
	TreeSet* subSet(int fromVal, int toVal);
	// return size of AVL tree
	int size();
	// recursive of add()
	AVLNode* recAdd(AVLNode* root, int val, bool taller);
	// balance tree
	AVLNode* leftBalance(AVLNode* root, bool taller);
	AVLNode* rightBalance(AVLNode* root, bool taller);
	// rotate tree
	AVLNode* rotateLeft(AVLNode* root);
	AVLNode* rotateRight(AVLNode* root);
	// return array of root
	int* toArray();
	// recursive of recToArray
	void recToArray(AVLNode* root, int values[], int index);
	// END HERE
};

