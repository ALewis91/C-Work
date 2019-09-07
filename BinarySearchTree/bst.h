
#ifndef BST_H
#define BST_H
// Modified for CSCI 220 Fall 15

#include "BinaryTree.h"
#include "RuntimeException.h"

template <typename E>
  class SearchTree {
  public:
    typedef typename E::Key K;    // a key
    typedeftypenameE::ValueV;     // a value
    class Iterator;               // an iterator/position
  public: 
    SearchTree(): T(), n(0)
    { T.addRoot(); T.expandExternal(T.root()); } // create the super root
       int size() const { return n; }   // number of entries
       bool empty() const { return n == 0; }  // is the tree empty
    Iterator find(const K& k) 
    {
        TPos v = finder(k, root());     // search for key from the virtual root
        if (!v.isExternal()) 
            return Iterator(v);  // if found, return it
        else 
            return end();                        // else if not found
    }
    
    Iterator insert(const K& k, const V& x)     // insert(k, x)
    { TPos v = inserter(k, x); return Iterator(v); }
    
    void erase(const K& k) 
    { 
        TPos v = finder(k, root()); // search from virtual root
        if (v.isExternal()) // not found?
            throw NonexistentElement("Erase of nonexistent");
         eraser(v);
    }
    
    void erase(const Iterator& p)   // remove entry at p
    { eraser(p.v); }
    
    Iterator begin()              // returns iterator at left most node
    {
          TPos v = root();        // start at root
          while (v.isInternal()) v = v.left();    // follow left child
          return Iterator(v.parent());            // return leftmost internal node
    }
     
    Iterator end()         // return iterator to end of of search entry, the super root
    { return Iterator(T.root()); }
     
  protected:           // local utilities
    typedef BinaryTree<E> BinaryTree;                 // linked binary tree
    typedef typename BinaryTree::Position TPos;       // position in the tree
    TPos root() const    { return T.root().left(); }  // left child of super root
        
    TPos finder(const K& k, TPos& v)
    {
          if (v.isExternal()) 
              return v; // key not found
          if (k < (*v).key()) 
              return finder(k, v.left()); // search left subtree 
          else if ((*v).key() < k) 
              return finder(k, v.right()); // search right subtree
          else
              return v;     // return the desired node
    }
      
    TPos inserter(const K& k, const V& x)
    {
          TPos v = finder(k, root());         // search from virtual root
          while (!v.isExternal())             // key already exists?
              v = finder(k, v.right());       // look further
          T.expandExternal(v);                // add new internal node
          (*v).setKey(k); (*v).setValue(x);   // set entry
          n++                                 // increment size
          return v;                           // return insert position
    }
      
    TPos eraser(TPos& v) 
    {
          TPos w;
          if (v.left().isExternal())  // remove from left
              w = v.left();
          else if (v.right().isExternal()) // remove from right
              w = v.right();
          else
          {
              w = v.right(); // go to right subtree
              do { w = w.left(); } while (!w.isExternal()); // get leftmost node
              TPos u = w.parent();
              (*v).setKey((*u).key()); (*v).setValue((*u).value()); // copy w's parent to v
          }
          n--; // decrement size
          return T.removeAboveExternal(w); // remove w and parent
    }
          
  private:
    BinaryTree T;
    int n;
  public:
    class Iterator 
    {
        private:
          TPos v;
        public:
          Iterator(const TPos& vv) : v(vv) { }
          const E& operator*() const { return *v; }   // get entry
          E& operator*() { return *v; }               // get entry
          bool operator==(const Iterator& p) const    // check if iterators are equal
            { return v.v == p.v.v; }
          Iterator& operator++()
          {
             TPos w = v.right();
             if (w.isInternal()) 
             {
                do { v = w; w = w.left(); }
                while (w.isInternal());
              }
              else 
              {
                 w = v.parent();
                 while (v == w.right())
                 { v = w; w = w.parent(); }
                 v = w;
                 return *this;
              }
          }
          friend class SearchTree;
     };
  };
#endif   






