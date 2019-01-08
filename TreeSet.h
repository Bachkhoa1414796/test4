///* Copyright (C) 2018
//* Course: CO2003
//* Author: Rang Nguyen
//* Ho Chi Minh City University of Technology
//*/
//
//#pragma once
//#include"AVLNode.h"
//
//class TreeSet
//{
//private:
//	AVLNode * root;
//	int count;
//
//protected:
//	void clearRec(AVLNode*root);
//	
//
//public:
//	TreeSet();
//	~TreeSet();
//	void clear();
//	// print out the set in ascending order
//	friend ostream& operator<<(ostream& os, const TreeSet& t);
//
//	// YOUR TASKS START HERE	
//	int add(int val);		
//	bool contains(int val);
//	void copy(const TreeSet& set);
//	int first();
//	int higher(int val);
//	int last();
//	int lower(int val);
//	int remove(int val);
//	TreeSet* subSet(int fromVal, int toVal);
//	int size();
//	// END HERE
//	void rotateLeft(AVLNode* tree);
//	void rotateRight(AVLNode* tree);
//	void balanceLeft(AVLNode* root, bool taller);
//	void balanceRight(AVLNode*root, bool taller);
//};
//
/* Copyright (C) 2018
* Course: CO2003
* Author: Rang Nguyen
* Ho Chi Minh City University of Technology
*/

#pragma once
#include"AVLNode.h"
class TreeSet
{
private:
	AVLNode * root = NULL;
	int count = 0;

protected:
	void clearRec(AVLNode*root);


public:
	TreeSet();
	~TreeSet();
	void clear();
	// print out the set in ascending order
	friend ostream& operator<<(ostream& os, const TreeSet& t);

	// YOUR TASKS START HERE	
	int add(int val);
	bool contains(int val);
	AVLNode* recContains(AVLNode* root, int val);
	void copy(const TreeSet& set);
	int first();
	AVLNode* recFirst(AVLNode* root);
	int higher(int val);
	int last();
	AVLNode* recLast(AVLNode* root);
	int lower(int val);
	int remove(int val);
	AVLNode* removeNode(AVLNode* &root, int val, bool shorter, bool success);
	AVLNode* deleteRightBalance(AVLNode* root, bool shorter);
	AVLNode* deleteLeftBalance(AVLNode* root, bool shorter);
	TreeSet* subSet(int fromVal, int toVal);
	int size();
	AVLNode* recAdd(AVLNode* root, int val, bool taller);
	AVLNode* leftBalance(AVLNode* root, bool taller);
	AVLNode* rightBalance(AVLNode* root, bool taller);
	AVLNode* rotateLeft(AVLNode* root);
	AVLNode* rotateRight(AVLNode* root);
	int* toArray();
	void recToArray(AVLNode* root, int values[], int index);
	// END HERE
};

