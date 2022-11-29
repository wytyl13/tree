/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-28 15:39:12
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-28 15:39:12
 * @Description: this file involved original binary search tree, 
 * equailiblim binary search tree. you can also name it balance bianry search tree.
 * the original bianry search tree has a simple insert function. you can use recursive method
 * to define the insert function. you should judge the insert value and the root value, 
 * if the former is less than the last, you should recursive recall the insert function and pass
 * the left child node as the param node. or you should pass the right child node as param.
 * this simple insert function will generate a big depth binary tree if you insert sequence data.
 * in order to solve this problem. we will add the equailiblim condition to the binary search tree, 
 * aim to limit the increase depth, you will get a balance depth in the bianry search tree.
 * the problem will focusing on the insert function.
 * 
 * AVL tree. Adelson-Velskii and Landis tree is a balance binary search tree.
 * the simple thought is gave the requirments that the left child node and right child node
 * should have the same depth. notice, the requirments is about the same depth, not the smallest depth,
 * you just need to ensure the same depth for left and right child. this condition is simple, but you should not
 * just require the root node has the same left and right child depth. just like as follow
 *                  8
 *              7       9
 *          6               10
 *      5                       11
 * this balance binary search tree is not efficient. but if you require each node
 * has the same depth left and right child, this condition will be too strict. it will
 * be bad implementation.
 * 
 * just like 56789 10, if you used the strict condition.
 *                      8
 *          
 *              6               10
 *          5       7        9      11          
 * you should use the most complex method to define this bianry search tree
 * with strict balance condition. so we can loosen the strict condition.
 * an AVL tree is a binary search tree that the left and right child node depth of each node is up to
 * one. it means the left child depth can be less 1  than the right child node depth.
 * notice, the depth of one node in binary tree is the largest node numbers from leaf to the node.
 * just like 56789 10
 *                      5
 *                          6
 *                              7
 * the left depth is 0 for the root node 5,
 * the right depth will be 2 for the root node after insert 7
 * if you do nothing, it will be not a AVL tree. so you should change the number
 *                      6
 *                  5       7
 *                              8   
 *                                  9
 * simily, the left child depth of root node is 1, 
 * the right depth of root node is 3 after you insert 9
 * so you should change the value.
 *                      7
 *                  6       8
 *              5               9
 *                                  10
 * the left node depth of 8 will be less 2 than right node after insert 10
 * so you should change the number.
 *                      7
 * 
 *              6               9
 *          5               8       10
 *                                      11
 * last, you will get the AVL tree. it is a balance binary search tree.
 * each node's one child node depth is up to 1 less than another child node depth.
 * it will be efficient.
 * then, we should consider how to implement the rule.
 * just like the above description. it will have four unbalance condition
 * after you insert one number. 
 * we can take an example for a node.
 *              a
 * 
 *      b               c
 * ?1       ?2      ?3      ?4
 *      first, the unbalance will happend when you insert the left child into the left child of a node. just like ?1 you want to insert
 *      second, the unbalance will happend when you insert the right child into the left child of a node. just like ?2 you want to insert.
 *      third, the unbalance will happend when you insert the left child into the right child of a node. just like ?3 you want to insert.
 *      fourth, the unbalance will happend when you insert the right child into the right child of a node. just like ?4 you want to insert.
 * then, we can define two method to solve these problem.
 *      first, we can devide two perspectives to consider these four issues.
 *      a situation is inserted into the outside of the binary search tree.
 *      a situation is inserted into the inside of the binary search tree.
 *      we can use the single rotation method to handle the first situation.
 *      we can use the double rotation method to handle the second situation.
 *      
 *      then, we will give a detail descrition about these two method.
 *      single ratation.
 *          it can handle two unbalance problem about insert into the outside of the tree.
 *          just like the case as follow, if ?1 is a node, the unbalance will not happend.
 *          because the left child of node a is b, and the b node depth is 1, and
 *          the right child of node a is c, and the c node depth is 0. so the b depth is greater 1
 *          than c node depth, it is balance bianry search tree.
 *          but if ?1 is a tree, the balance will be broken.
 *          so we leads to a new problem, it is insert node or a tree node.
 *              a
 * 
 *      b               c
 * ?1         
 *          if this case happend above, we can use single rotation to handle it.
 *          single rotation is simple. but double rotation is very complex. so 
 *          we will not do theoretical annalysis about it, we will give the code directly
 *          and understand it by reading code.
 * although the AVL tree is a special tree, but its tree structure is different from an original bianry tree.
 * so we will redefine the AVL struct. and the makeEmpty, find, findMin, findMax function
 * can use the method of original binary search tree.
 * so we will include searchTree head file. and we just need to define these new function,
 * just like insert, delete and so on. but we need to create a new file for AVL tree.
 * because the struct is different from original bianry search tree.
***********************************************************************/
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
// this insert function is simple, a original bianry search tree
SearchTreeP insert(SearchTreeP searchTreeP, ElementIntType elementInt);
SearchTreeP delete(SearchTreeP searchTreeP, ElementIntType elementInt);
ElementType retriver(SearchTreeP searchTreeP);

// then we will define a bianry search tree with equilibrium conditions.
// how to define, it is a special binary tree, you should redefine a complex
// insert function.
// to test the convenient, we defined the preorder, inorder and postorder method for search tree.
// these three travesal method is general used for binary search tree and avl binary search tree.
// because they have the same attribute ElementInt to store the number.
// so you should use the void * to accept the param.
// but you should cast first before you used the pointer that void accept,
// so you can not use the general method to define this function.
// so we will define it in AVLTree file. or you can use c++ class to do it.
// but it is not meaning, because we just aimed to learn, not to do business application.
void preOrderSearchTree(SearchTreeP searchTreeP, int depth);
void inOrderSearchTree(SearchTreeP searchTreeP, int depth);
void postOrderSearchTree(SearchTreeP searchTreeP, int depth);
#endif