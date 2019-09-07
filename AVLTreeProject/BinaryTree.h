#pragma once
#include <list>
#include <iostream>
#include "Entry.h"
using namespace std;

class BinaryTree
{
protected:
	struct Node 
	{
		Entry e;
		Node*   par;
		Node*   left;
		Node*   right;
		Node() : e(), par(NULL), left(NULL), right(NULL) { }
	};
public:
	class Position
	{
	public:
		Node* v;
	public:
		Position(Node* _v = NULL);
		Entry& operator*();
		bool operator==(Position p);
		Position left() const;
		Position right() const;
		Position parent() const;
		bool isRoot() const;
		bool isExternal() const;
		const int height() const;
		void setHeight(int h);

		friend class BinaryTree;
	};
	typedef std::list<Position> PositionList;
public:
	BinaryTree();
	int size() const;
	bool empty() const;
	Position root() const;
	PositionList positions() const;
	void addRoot();	
	void expandExternal(const Position& p);
	Position removeAboveExternal(const Position& p);

protected: 					
	void preorder(Node* v, PositionList& pl) const;	
	void inorder(Node* v, PositionList& pl) const;
private:
	Node* _root;		
	int n;				

	friend class SearchTree;
};
