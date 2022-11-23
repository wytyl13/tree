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

// then you should define some tree management method.
// just like init tree. traversal, and so on.
// this binary tree should original a binaryNode.
// so you should init a binaryNode in this function.
// we will create a TreeP pointer and init its left and right child used null in this function.
// and you should return the TreeP last, we will used it as root.
void initBinaryTree(TreeP treeP, ElementType element);

// then, define a function, that transform from a postfix expression to expression tree.
/**
 * @Author: weiyutao
 * @Date: 2022-11-21 22:23:33
 * @Parameters: postfix expression, we used the return queue from expression.c file. it store the transformed postfix expression.
 * @Return: return a expression tree. its structure is bianry tree.
 * @Description: you will use stack as tool. 
 *      if meet numbers, create tree node and push the pointer that pointing to it into stack.
 *      if meet operator, pop two element from stack, define the left child of this operator is
 *      the first pop element's address, the right child of this operator is the second pop elemnt's address.
 *      then and so on.
 * you will transform from the postfix expression in linkQueue to expression tree
 * in treeP, and you will use stack as tool to store the temp data.
 */
TreeP transformTree(LinkQueueP linkQueueP);


// define the function taversal a binary tree.
// involved inorder traversal, preorder traversal and postorder traversal
void preOrderTraversal(TreeP root, int depth);


#endif


