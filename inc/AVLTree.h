/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-29 11:41:05
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-29 11:41:05
 * @Description: in order to more efficient, we will add the height attribute
 * for AVLNode, because we can judge the legitimacy about AVL tree based on the 
 * height attribute. and the original binary search tree has not this attribute.
***********************************************************************/
#ifndef _AVLTREE_H
#define _AVLTREE_H

#include "searchTree.h"
struct AvlNode;
typedef struct AvlNode AvlTree, *AvlTreeP;

struct AvlNode
{
    ElementIntType ElementInt;
    AvlTreeP Left;
    AvlTreeP Right;
    int Height;
};

AvlTreeP insertAvl(AvlTreeP avlTreeP, ElementIntType elementInt);
AvlTreeP deleteAvl(AvlTreeP avlTreeP, ElementIntType elementInt);
ElementIntType retrieve(AvlTreeP avlTreeP);
#endif