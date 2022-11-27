
#ifndef _SEARCHTREE_H
#define _SEARCHTREE_H

#include "link.h"

typedef struct SearchNode SearchTree, *SearchTreeP;
struct SearchNode
{
    ElementIntType ElementInt;
    SearchTreeP Left;
    SearchTreeP Right;
};

// define the function about searchTree

// it is also a function that init this root pointer
// because we want to init this root, so we should return a 
// null searchTree pointer.
SearchTreeP makeEmpty(SearchTreeP searchTreeP);
// this function should return a pointer that store this elementInt
SearchTreeP find(SearchTreeP searchTreeP, ElementIntType elementInt);
SearchTreeP findMin(SearchTreeP searchTreeP);
SearchTreeP findMax(SearchTreeP searchTreeP);
SearchTreeP insert(SearchTreeP searchTreeP, ElementIntType elementInt);
SearchTreeP delete(SearchTreeP searchTreeP, ElementIntType elementInt);
ElementType retriver(SearchTreeP searchTreeP);

// to test the convenient, we defined the preorder, inorder and postorder method for search tree.
void preOrderSearchTree(SearchTreeP searchTreeP, int depth);
void inOrderSearchTree(SearchTreeP searchTreeP, int depth);
void postOrderSearchTree(SearchTreeP searchTreeP, int depth);
#endif