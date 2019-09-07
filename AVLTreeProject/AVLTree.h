#pragma once
#include "SearchTree.h"
#include <algorithm>

class AVLTree : public SearchTree
{
public:
	typedef SearchTree::Iterator Iterator;
protected:
	typedef SearchTree::TPos TPos;
public:
	AVLTree();
	Iterator insert(const std::string& code, const int& pop, const std::string& name);
	void erase(const std::string& code) throw(NonexistentElement);
	void erase(Iterator& p);
	void inorder(PositionList& pl) const;
	void levelorder(PositionList& pl) const;
protected:
	int height(const TPos& v) const;
	void setHeight(TPos v);
	bool isBalanced(const TPos& v) const;
	TPos tallGrandchild(const TPos& z) const;
	void rebalance(const TPos& v);
};
