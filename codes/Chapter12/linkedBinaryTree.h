
// linked binary tree using nodes of type binaryTreeNode
// derives from the abstract class binaryTree

#ifndef linkedBinaryTree_
#define linkedBinaryTree_

using namespace std;

#include "binaryTree.h"
#include "arrayQueue.h"
#include "binaryTreeNode.h"
#include "myExceptions.h"
#include "booster.h"

#include <iostream>
#include <map> 
using namespace std; 

template<class E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E> >
{
   public:
      linkedBinaryTree() {this->root = NULL; treeSize = 0;}
      ~linkedBinaryTree(){erase();}; 
      bool empty() const {return treeSize == 0;}
      int size() const {return treeSize;}
      E* rootElement() const;
      void makeTree(const E& element,
           linkedBinaryTree<E>&, linkedBinaryTree<E>&);
      linkedBinaryTree<E>& removeLeftSubtree();
      linkedBinaryTree<E>& removeRightSubtree();
      void preOrder(void(*theVisit)(binaryTreeNode<E>*))
           {visit = theVisit; preOrder(this->root);}
      void inOrder(void(*theVisit)(binaryTreeNode<E>*))
           {visit = theVisit; inOrder(this->root);}
      void postOrder(void(*theVisit)(binaryTreeNode<E>*))
           {visit = theVisit; postOrder(this->root);}
      void levelOrder(void(*)(binaryTreeNode<E> *));
      void preOrderOutput() {preOrder(output); std::cout << endl;}
      void inOrderOutput() {inOrder(output); std::cout << endl;}
      void postOrderOutput() {postOrder(output); std::cout << endl;}
      void levelOrderOutput() {levelOrder(output); std::cout << endl;}
      void erase()
           {
              postOrder(dispose);
              this->root = NULL;
              treeSize = 0;
           }
      int height() const {return height(this->root);}
   protected:
      binaryTreeNode<E> *root;                // pointer to root
      int treeSize;                           // number of nodes in tree
      static void (*visit)(binaryTreeNode<E>*);      // visit function
      static int count;         // used to count nodes in a subtree
      static void preOrder(binaryTreeNode<E> *t);
      static void inOrder(binaryTreeNode<E> *t);
      static void postOrder(binaryTreeNode<E> *t);
      static void countNodes(binaryTreeNode<E> *t)
                  {
                     visit = addToCount; 
                     count = 0;
                     preOrder(t);
                  }
      static void dispose(binaryTreeNode<E> *t) {delete t;}
      static void output(binaryTreeNode<E> *t)
                  {cout << t->element << ' ';}
      static void addToCount(binaryTreeNode<E> *t)
                  {count++;}
      static int height(binaryTreeNode<E> *t);
};
// the following should work but gives an internal compiler error
// template <class E> void (*linkedBinaryTree<E>::visit)(binaryTreeNode<E>*);
// so the explicit declarations that follow are used for our purpose instead
template<> void (*linkedBinaryTree<int>::visit)(binaryTreeNode<int>*);
template<> void (*linkedBinaryTree<booster>::visit)(binaryTreeNode<booster>*);
template<> void (*linkedBinaryTree<pair<int,int> >::visit)(binaryTreeNode<pair<int,int> >*);
template<> void (*linkedBinaryTree<pair<const int,char> >::visit)(binaryTreeNode<pair<const int,char> >*);
template<> void (*linkedBinaryTree<pair<const int,int> >::visit)(binaryTreeNode<pair<const int,int> >*);

template<class E>
E* linkedBinaryTree<E>::rootElement() const
{// Return NULL if no root. Otherwise, return pointer to root element.
   if (treeSize == 0)
      return NULL;  // no root
   else
      return &this->root->element;
}

template<class E>
void linkedBinaryTree<E>::makeTree(const E& element,
           linkedBinaryTree<E>& left, linkedBinaryTree<E>& right)
{// Combine left, right, and element to make new tree.
 // left, right, and this must be different trees.
   // create combined tree
   this->root = new binaryTreeNode<E> (element, left.root, right.root);
   treeSize = left.treeSize + right.treeSize + 1;

   // deny access from trees left and right
   left.root = right.root = NULL;
   left.treeSize = right.treeSize = 0;
}

template<class E>
linkedBinaryTree<E>& linkedBinaryTree<E>::removeLeftSubtree()
{// Remove and return the left subtree.
   // check if empty
   if (treeSize == 0)
      throw string("emptyTree()");

   // detach left subtree and save in leftSubtree
   linkedBinaryTree<E> leftSubtree;
   leftSubtree.root = this->root->leftChild;
   count = 0;
   leftSubtree.treeSize = countNodes(leftSubtree.root);
   this->root->leftChild = NULL;
   treeSize -= leftSubtree.treeSize;
  
   return leftSubtree;
}

template<class E>
linkedBinaryTree<E>& linkedBinaryTree<E>::removeRightSubtree()
{// Remove and return the right subtree.
   // check if empty
   if (treeSize == 0)
      throw string ("emptyTree()");

   // detach right subtree and save in rightSubtree
   linkedBinaryTree<E> rightSubtree;
   rightSubtree.root = this->root->rightChild;
   count = 0;
   rightSubtree.treeSize = countNodes(rightSubtree.root);
   this->root->rightChild = NULL;
   treeSize -= rightSubtree.treeSize;
  
   return rightSubtree;
}

template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t)
{// Preorder traversal.
   if (t != NULL)
   {
      linkedBinaryTree<E>::visit(t);
      preOrder(t->leftChild);
      preOrder(t->rightChild);
   }
}

template<class E>
void linkedBinaryTree<E>::inOrder(binaryTreeNode<E> *t)
{// Inorder traversal.
   if (t != NULL)
   {
      inOrder(t->leftChild);
      linkedBinaryTree<E>::visit(t);
      inOrder(t->rightChild);
   }
}

template<class E>
void linkedBinaryTree<E>::postOrder(binaryTreeNode<E> *t)
{// Postorder traversal.
   if (t != NULL)
   {
      postOrder(t->leftChild);
      postOrder(t->rightChild);
      linkedBinaryTree<E>::visit(t);
   }
}

template <class E>
void linkedBinaryTree<E>::levelOrder(void(*theVisit)(binaryTreeNode<E> *))
{// Level-order traversal.
   arrayQueue<binaryTreeNode<E>*> q;
   binaryTreeNode<E> *t = this->root;
   while (t != NULL)
   {
      theVisit(t);  // visit t

      // put t's children on queue
      if (t->leftChild != NULL)
         q.push(t->leftChild);
      if (t->rightChild != NULL)
         q.push(t->rightChild);

      // get next node to visit
      try {t = q.front();}
      catch (queueEmpty) {return;}
      q.pop();
   }
}

template <class E>
int linkedBinaryTree<E>::height(binaryTreeNode<E> *t)
{// Return height of tree rooted at *t.
   if (t == NULL)
      return 0;                    // empty tree
   int hl = height(t->leftChild);  // height of left
   int hr = height(t->rightChild); // height of right
   if (hl > hr)
      return ++hl;
   else
      return ++hr;
}

#endif
