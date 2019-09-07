#include "SearchTree.h"

SearchTree::SearchTree() : T(), n(0), units(0)
{
	T.addRoot(); T.expandExternal(T.root());
}

int SearchTree::size() const 
{ 
	return n; 
}
bool SearchTree::empty() const 
{ 
	return n == 0; 
}
SearchTree::Iterator SearchTree::find(const std::string& code) 
{
	units = 0;
	TPos v = finder(code, root());
	if (!v.isExternal()) 
		return Iterator(v);
	else 
		return end();
}
SearchTree::Iterator SearchTree::insert(const std::string& code, const int& pop, const std::string& name)	
{
	TPos v = inserter(code, pop, name); 
	return Iterator(v);
}

void SearchTree::erase(const std::string& code) throw(NonexistentElement) 
{
	TPos v = finder(code, root());			
	if (v.isExternal())
		throw NonexistentElement("Erase of nonexistent");

	eraser(v);					
}

void SearchTree::erase(Iterator& p)
{
	eraser(p.v);
}
SearchTree::Iterator SearchTree::begin() 
{
	TPos v = root();			
	while (!v.isExternal()) v = v.left();
	return Iterator(v.parent());
}
SearchTree::Iterator SearchTree::end()		
{
	return Iterator(T.root());
}

SearchTree::TPos SearchTree::root() const 
{ 
	return T.root().left(); 
}

SearchTree::TPos SearchTree::finder(const std::string& code, TPos& v) 
{
	units++;
	if (v.isExternal())
		return v;
	if (stoi(code) < stoi((*v).areaCode()))
	{
		//std::cout << "\nLeft of " << stoi((*v).areaCode());
		return finder(code, v.left());
	}
	else if (stoi(code) > stoi((*v).areaCode()))
	{
		//std::cout << "\nRight of " << stoi((*v).areaCode());
		return finder(code, v.right());
	}
	else
		return v;

}

SearchTree::TPos SearchTree::inserter(const std::string& code, const int& pop, const std::string& name) {
	TPos v = finder(code, root());
	while (!v.isExternal())		
		v = finder(code, v.right());
	T.expandExternal(v);				
	(*v).setCode(code);
	(*v).setPopulation(pop);
	(*v).setAreaName(name);
	n++;					
	return v;						
}
SearchTree::TPos SearchTree::eraser(TPos& v) 
{
	TPos w;
	if (v.left().isExternal())
		w = v.left();	
	else if (v.right().isExternal()) 
		w = v.right();
	else 
	{					
		w = v.left();				
		do { w = w.right(); } while (!w.isExternal());	
		TPos u = w.parent();
		(*v).setCode((*u).areaCode());
		(*v).setPopulation((*u).population());
		(*v).setAreaName((*u).areaName());
	}
	n--;						
	return T.removeAboveExternal(w);	
}

SearchTree::TPos SearchTree::restructure(const TPos& v)
{
	TPos x = v;
	TPos y = TPos(x.v->par);
	TPos z = TPos(y.v->par);
	TPos a;
	TPos b;
	TPos c;
	TPos t1;
	TPos t2;
	TPos t3;
	TPos t4;

	if ((*x).areaCode() >= (*y).areaCode()
		&& (*y).areaCode() >= (*z).areaCode())
	{
		a = z;
		b = y;
		c = x;
		t1 = a.left();
		t2 = b.left();
		t3 = c.left();
		t4 = c.right();
	}
	else if ((*x).areaCode() <= (*y).areaCode()
		&& (*y).areaCode() <= (*z).areaCode())
	{
		a = x;
		b = y;
		c = z;
		t1 = a.left();
		t2 = a.right();
		t3 = b.right();
		t4 = c.right();
	}
	else if ((*x).areaCode() <= (*y).areaCode()
		&& (*y).areaCode() >= (*z).areaCode())
	{
		a = z;
		b = x;
		c = y;
		t1 = a.left();
		t2 = b.left();
		t3 = b.right();
		t4 = c.right();
	}
	else
	{
		a = y;
		b = x;
		c = z;
		t1 = a.left();
		t2 = b.left();
		t3 = b.right();
		t4 = c.right();
	}

	if (z.v == T.root().left().v)
	{
		T._root->left = b.v;
		b.v->par = T._root;
	}
	else if (z.v->par->left == z.v)
		z.v->par->left = b.v;
	else
		z.v->par->right = b.v;

	b.v->left = a.v;
	b.v->right = c.v;
	b.v->par = z.v->par;
	a.v->left = t1.v;
	t1.v->par = a.v;
	a.v->right = t2.v;
	t2.v->par = a.v;
	a.v->par = b.v;
	c.v->left = t3.v;
	t3.v->par = c.v;
	c.v->right = t4.v;
	t4.v->par = c.v;
	c.v->par = b.v;

	return b;
}

void SearchTree::inorder(const TPos&v, PositionList& pl) const
{
	if (!v.left().isExternal())
		inorder(v.left(), pl);
	pl.push_back(v);
	if (!v.right().isExternal())
		inorder(v.right(), pl);
}

void SearchTree::levelorder(const TPos&v, PositionList& pl) const
{
	PositionList temp;
	temp.push_back(v);
	while (!temp.empty())
	{
		if (!temp.front().left().isExternal())
			temp.push_back(temp.front().left());
		if (!temp.front().right().isExternal())
			temp.push_back(temp.front().right());

		pl.push_back(temp.front());
		temp.pop_front();
	}
}
SearchTree::Iterator::Iterator(const TPos& vv) : v(vv) { }

Entry& SearchTree::Iterator::operator*()
{
	return *v;
}
bool SearchTree::Iterator::operator==(const Iterator& p) const
{
	return v.v == p.v.v;
}
SearchTree::Iterator &SearchTree::Iterator::operator++()
{
	TPos w = v.right();
	if (!w.isExternal()) {			
		do { v = w; w = w.left(); }		
		while (!w.isExternal());
	}
	else {
		w = v.parent();				
		while (&v == &w.right())			
		{
			v = w; w = w.parent();
		}
		v = w;					
	}
	return *this;
}


int SearchTree::getUnits() const
{
	return units;
}
