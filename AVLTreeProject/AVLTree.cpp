#pragma once
#include "AVLTree.h"

AVLTree::AVLTree()
{
	SearchTree();
}

int AVLTree::height(const TPos& v) const
{
	return (v.isExternal() ? 0 : v.height());
}

void AVLTree::setHeight(TPos v)
{
	int hl = height(v.left());
	int hr = height(v.right());
	v.setHeight(1 + std::max(hl, hr));
}

bool AVLTree::isBalanced(const TPos& v) const
{
	int bal = height(v.left()) - height(v.right());
	return ((-1 <= bal) && (bal <= 1));
}

void AVLTree::rebalance(const TPos& v)
{
	TPos z = v;
	while (!(z.v == SearchTree::root().v))
	{
		z = z.parent();
		setHeight(z);
		if (!isBalanced(z))
		{
			TPos x = tallGrandchild(z);
			z = restructure(x);
			setHeight(z.left());
			setHeight(z.right());
			setHeight(z);
		}
	}
}

AVLTree::Iterator AVLTree::insert(const std::string& code, const int& pop, const std::string& name)
{
	TPos v = inserter(code, pop, name);
	setHeight(v);
	rebalance(v);
	return Iterator(v);
}

void AVLTree::erase(const std::string& code) throw (NonexistentElement)
{
	TPos v = finder(code, SearchTree::root());
	if (Iterator(v) == SearchTree::end())
		throw NonexistentElement("Erase of nonexistent");
	else if (v.isExternal())
		throw NonexistentElement("Erase of nonexistent");
	TPos w = eraser(v);
	rebalance(w);
}

void AVLTree::erase(Iterator& p)
{
	erase((*p).areaCode());
}

SearchTree::TPos AVLTree::tallGrandchild(const TPos& z) const
{
	TPos zl = z.left();
	TPos zr = z.right();
	if (height(zl) >= height(zr))
	{
		if (height(zl.left()) >= height(zl.right()))
			return zl.left();
		else
			return zl.right();
	}
	else
	{
		if (height(zr.right()) >= height(zr.left()))
			return zr.right();
		else
			return zr.left();
	}
}

void AVLTree::inorder(PositionList& pl) const
{
	SearchTree::inorder(root(), pl);
}

void AVLTree::levelorder(PositionList& pl) const
{
	SearchTree::levelorder(root(), pl);
}
