#include "BinaryTree.h"
#include "RuntimeException.h"
#include <math.h>
#include <iomanip>
#include <iostream>

class SearchTree
{

public:
	class Iterator;
public:
	SearchTree();
	int size() const;
	bool empty() const;
	Iterator find(const std::string& code);
	Iterator insert(const std::string& code, const int& pop, const std::string& name);
	void erase(const std::string& code);
	void erase(Iterator& p);
	Iterator begin();
	Iterator end();	
	typedef typename BinaryTree::Position TPos;
	typedef BinaryTree::PositionList PositionList;
	int getUnits() const;
protected:			
	TPos root() const;
	TPos finder(const std::string& code, TPos& v);
	TPos inserter(const std::string& code, const int& pop, const std::string& name);
	TPos eraser(TPos& v);
	TPos restructure(const TPos& v);
	void inorder(const TPos&v, PositionList& pl) const;
	void levelorder(const TPos&v, PositionList& pl) const;

private: 					
	BinaryTree T;			
	int n;
	int units;
public:
	class Iterator 
	{	                      		
	private:
		TPos v;					
	public:
		Iterator(const TPos& vv);
		Entry& operator*();
		bool operator==(const Iterator& p) const;
		Iterator& operator++();
		friend class SearchTree;	
	};
};
