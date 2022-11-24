/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-17 16:21:14
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-17 16:21:14
 * @Description: this file is head file about tree, that involved original
 * tree, binary tree and some special binary tree, just like red black tree.
 * B-tree and B+tree. you should notice the differece between origianl tree and
 * binary tree. the details of description in main.c
 * 
 * we have defined the expression tree, involved transform from inorder expression
 * to postfix expression. and traversal the expression tree used preorder, inorder, postorder.
 * then we will learn about bianry search tree. for each node x in the tree, its left child number
 * is less than its right child numbers. only own this feature, this tree can only conform to the 
 * search binary tree. because the bianry search tree based on the element is int type, and the tree
 * we have defined are all char, so we should redefine a element is void type or int type tree.
 * 
***********************************************************************/

#ifndef _TREE_H
#define _TREE_H
#include "queue.h"
#include "stack.h"
// typedef int ElementType;

struct OriginalNode;
struct BinaryNode;
typedef struct OriginalNode *PtrToNode;
typedef struct BinaryNode Tree, *TreeP;
typedef struct SearchNode SearchTree, *SearchTreeP;

struct OriginalNode
{
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};

struct BinaryNode
{
    ElementType Element;
    TreeP Left;
    TreeP Right;
};

struct SearchNode
{
    ElementIntType ElementInt;
    SearchTreeP Left;
    SearchTreeP Right;
};

// then you should define some tree management method.
// just like init tree. traversal, and so on.
// this binary tree should original a binaryNode.
// so you should init a binaryNode in this function.
// we will create a TreeP pointer and init its left and right child used null in this function.
// and you should return the TreeP last, we will used it as root.
void
initBinaryTree(TreeP treeP, ElementType element);

// then, define a function, that transform from a postfix expression to expression tree.
/**
 * @Author: weiyutao
 * @Date: 2022-11-21 22:23:33
 * @Parameters: postfix expression, we used the return queue from expression.c file. it store the transformed postfix expression.
 * @Return: return a expression tree. its structure is bianry tree.
 * @Description: you will use stack as tool. 
 *      if meet numbers, create tree node and push the pointer that pointing to it into stack.
 *      if meet operator, pop two element from stack, define the right child of this operator is
 *      the first pop element's address, the left child of this operator is the second pop elemnt's address.
 *      then and so on.
 * you will transform from the postfix expression in linkQueue to expression tree
 * in treeP, and you will use stack as tool to store the temp data.
 */
TreeP transformTree(LinkQueueP linkQueueP);


// define the function taversal a binary tree.
// involved inorder traversal, preorder traversal and postorder traversal
void preOrderTraversal(TreeP root, int depth);

void postOrderTraversal(TreeP root, int depth);

void inOrderTraversal(TreeP root, int depth);


// define the function about searchTree
SearchTreeP makeEmpty(SearchTreeP searchTreeP);
SearchTreeP find(SearchTreeP searchTreeP, ElementIntType elementInt);
SearchTreeP findMin(SearchTreeP searchTreeP);
SearchTreeP findMax(SearchTreeP searchTreeP);
SearchTree insert(SearchTreeP searchTreeP, ElementIntType elementInt);
SearchTree delete(SearchTreeP searchTreeP, ElementIntType elementInt);
ElementType retriver(SearchTreeP searchTreeP);


#endif


