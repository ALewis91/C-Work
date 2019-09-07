
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Modified for CSCI 220 Fall 13

#include <list>


using namespace std;
//typedef int Elem;

template <typename Elem>
class BinaryTree {
    protected:
       struct Node {        // a node of the tree
          Elem    elt;  // element value
          Node*  par;  // parent
          Node* left;  // left child
          Node* right; // right child
          Node() : elt(), par(NULL), left(NULL), right(NULL) {} // constructor
        }; 
        
     public:
     class Position {
       public:
              Node* v;      // position in the tree
       public:
              Position(Node* _v = NULL) : v(_v) { } // constructor
              
              Elem& operator*()                     // get element
              {
                     return v->elt;
              }
              
              Position left() const                 // get left child
              {
                     return Position(v->left);
              }
              
              Position right() const                // get right child
              {
                     return Position(v->right);
              }
              
              Position parent() const               // get parent
              { 
                     return Position(v->par);
              }
              
              bool isRoot() const                   // is root of the tree?
              {
                     return v->par == NULL;
              }
              
              bool isExternal() const               // is a leaf node?
              {
                     return v->left == NULL && v->right == NULL;
              }

              friend class BinaryTree;              // give binary tree access
       };
       
       typedef std::list<Position> PositionList;
       
    public:
            BinaryTree();         // constructor
            int size() const;     // number of nodes
            bool empty() const;   // is tree empty?
            
            Position root() const // get the root
            {
                   return Position(_root);
            }
            
            PositionList positions() const  // list of nodes
            {
                   PositionList pl;
                   preorder(_root, pl);     // preorder traversal
                   return PositionList(pl); // return resulting list
            }
            
            void addRoot();                           // add root to empty tree
            void expandExternal(const Position& p);   // expand external node
            Position removeAboveExternal(const Position& p) // remove p and parent
            {
                Node* w = p.v;  Node* v = w->par;           // get p's node and parent
                Node* sib = (w == v->left ? v->right : v->left);
                if (v == _root) {      // child of root?
                      _root = sib;     // make sibling root
                      sib->par = NULL;
                }
                else {
                      Node* gpar = v->par;    // w's grandparent
                      if (v == gpar->left)    // replace parent by sibling
                          gpar->left = sib;
                      else
                          gpar->right= sib;
                      sib->par = gpar;
                }
                
                delete w;       // delete removed nodes
                delete v;
                n -= 2;         // decrement size by 2
                return Position(sib);
             }
  protected:
      void preorder(Node* v, PositionList& pl) const; // preorder utility
  private:
    Node* _root; // pointer to the root 
    int n; // number of nodes
};

template <typename Elem>
BinaryTree<Elem>::BinaryTree()    // constructor
       : _root(NULL), n(0) { }
       
template <typename Elem>            // number of nodes
int BinaryTree<Elem>::size() const
{
  return n; 
}


template <typename Elem>              // is tree empty
bool BinaryTree<Elem>::empty() const
{
       return size() == 0;
}

template <typename Elem>          // add root to empty tree
void BinaryTree<Elem>::addRoot()
{
       _root = new Node; n = 1;
}

template <typename Elem>
void BinaryTree<Elem>::expandExternal(const Position& p) 
{
    Node* v = p.v;        // p's node
    v->left = new Node;   // add a new left child
    v->left->par = v;     // v is its parent
    v->right = new Node;  // add a new right child
    v->right->par = v;    // v is its parent
    n+=2;                 // increment number of nodes
}

template <typename Elem>
void BinaryTree<Elem>::preorder(Node* v, PositionList& pl) const // preorder traversal
{
    pl.push_back(Position(v));    // add this node to the list
    if (v->left != NULL)          // traverse left subtree
           preorder(v->left, pl);
    if (v->right != NULL)         // traverse right subtree
           preorder(v->right, pl);
}
#endif
             
