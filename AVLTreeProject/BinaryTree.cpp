#include "BinaryTree.h"

////////////////////////////////////////////////////
//                                                //
//               Position Class                   //
//                                                //
////////////////////////////////////////////////////

BinaryTree::Position::Position(Node* _v) : v(_v) { }
Entry& BinaryTree::Position::operator*()
{
	return v->e;
}
bool BinaryTree::Position::operator==(Position p)
{
	return &v == &(p.v);
}
BinaryTree::Position BinaryTree::Position::left() const				// get left child
{
	return Position(v->left);
}
BinaryTree::Position BinaryTree::Position::right() const				// get right child
{
	return Position(v->right);
}
BinaryTree::Position BinaryTree::Position::parent() const				// get parent
{
	return Position(v->par);
}
bool BinaryTree::Position::isRoot() const				// root of the tree?
{
	return v->par == NULL;
}
bool BinaryTree::Position::isExternal() const				// an external node?
{
	return v->left == NULL && v->right == NULL;
}
const int BinaryTree::Position::height() const
{
	return v->e.height();
}
void BinaryTree::Position::setHeight(int h)
{
	v->e.setHeight(h);
}

////////////////////////////////////////////////////
//                                                //
//             BinaryTree Class                   //
//                                                //
////////////////////////////////////////////////////

BinaryTree::BinaryTree()		
	: _root(NULL), n(0) { }

int BinaryTree::size() const		
{
	return n;
}

bool BinaryTree::empty() const		
{
	return size() == 0;
}
BinaryTree::Position BinaryTree::root() const
{
	return Position(_root);
}

BinaryTree::PositionList BinaryTree::positions() const 
{
	PositionList pl;
	preorder(_root, pl);		
	return PositionList(pl);	
}
void BinaryTree::addRoot()		
{
	_root = new Node; n = 1;
}

void BinaryTree::expandExternal(const Position& p) 
{
	Node* v = p.v;
	v->left = new Node;
	v->left->par = v;
	v->right = new Node;
	v->right->par = v;
	n += 2;
}

void BinaryTree::preorder(Node* v, PositionList& pl) const 
{
	pl.push_back(Position(v));
	if (v->left != NULL)
		preorder(v->left, pl);
	if (v->right != NULL)
		preorder(v->right, pl);
}
void BinaryTree::inorder(Node* v, PositionList& pl) const
{
	if (v->left != NULL)
		inorder(v->left, pl);
	pl.push_back(Position(v));
	if (v->right != NULL)
		inorder(v->right, pl);
}

BinaryTree::Position BinaryTree::removeAboveExternal(const Position& p)
{
	Node* w = p.v;  Node* v = w->par;
	Node* sib = (w == v->left ? v->right : v->left);
	if (v == _root) {					
		_root = sib;			
		sib->par = NULL;
	}
	else {
		Node* gpar = v->par;				
		if (v == gpar->left) gpar->left = sib; 		
		else gpar->right = sib;
		sib->par = gpar;
	}
	delete w; delete v;		
	n -= 2;					
	return Position(sib);
}
