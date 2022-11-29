#include "../inc/AVLTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static AvlTreeP singleRotationWithLeft(AvlTreeP root);
static AvlTreeP singleRotationWithRight(AvlTreeP root);
static AvlTreeP doubleRotationWithLeft(AvlTreeP root);
static AvlTreeP doubleRotationWithLeft(AvlTreeP root);
static int height(AvlTreeP avlTreeP);
static int max(int a, int b);

/**
 * @Author: weiyutao
 * @Date: 2022-11-29 13:59:01
 * @Parameters: 
 * @Return: 
 * @Description: then, we will define the single rotation used a case
 *                  root                                   node1       
 *      
 *       node1                  node2           node3               root
 * 
 * node3        node4                                         node4         node2      
 * just like the case above. this singleRotation just show the rotation,
 * it is on  the premise of successful insert based on the faeture of AVL tree.
 * this singleRotation function aims to change the value position.
 */
static AvlTreeP singleRotationWithLeft(AvlTreeP root) 
{
    AvlTreeP node1;
    node1 = root->Left;
    root->Left = node1->Right;
    node1->Right = root;
    // update the Height attribute
    root->Height = max(height(root->Left), height(root->Right)) + 1;
    node1->Height = max(height(node1->Left), root->Height) + 1;
    return node1;
}

static AvlTreeP singleRotationWithRight(AvlTreeP root) 
{
    AvlTreeP node1;
    node1 = root->Right;
    root->Right = node1->Left;
    node1->Left = root;

    root->Height = max(height(root->Right), height(root->Left)) + 1;
    node1->Height = max(height(node1->Right), root->Height) + 1;
    return node1;
}

static AvlTreeP doubleRotationWithLeft(AvlTreeP root) 
{
    root->Left = singleRotationWithRight(root->Left);

    return singleRotationWithLeft(root);
}

static AvlTreeP doubleRotationWithRight(AvlTreeP root) 
{
    root->Right = singleRotationWithLeft(root->Right);

    return singleRotationWithRight(root);
}

static int height(AvlTreeP avlTreeP) 
{
    // this height is original from -1.
    if (avlTreeP == NULL)
    {
        return -1;
    }
    return avlTreeP->Height;
}

static int max(int a, int b) 
{
    if (a > b)
    {
        return a;
    }
    return b;
}

AvlTreeP insertAvl(AvlTreeP avlTreeP, ElementIntType elementInt) 
{
    if (avlTreeP == NULL)
    {
        // init the avlTreeP
        avlTreeP = (AvlTreeP)malloc(sizeof(AvlTree));
        if (avlTreeP == NULL)
        {
            sysError("out of space, malloc error!");
        }
        else
        {
            avlTreeP->ElementInt = elementInt;
            avlTreeP->Left = avlTreeP->Right = NULL;
        }
    }
    else if (elementInt < avlTreeP->ElementInt)
    {
        // recursive move to left.
        avlTreeP->Left = insertAvl(avlTreeP->Left, elementInt);
        if (height(avlTreeP->Left) - height(avlTreeP->Right) == 2)
        {
            if (elementInt < avlTreeP->Left->ElementInt)
            {
                // insert left left, outside of the tree.
                // you should use single rotation to handle it.
                avlTreeP = singleRotationWithLeft(avlTreeP);
            }
            else
            {
                // insert left right, inside of the tree.
                // you should use double rotation to handle it.
                avlTreeP = doubleRotationWithLeft(avlTreeP);
            }
        }
    }else if (elementInt > avlTreeP->ElementInt)
    {
        // recursive move to right.    
        avlTreeP->Right = insertAvl(avlTreeP->Right, elementInt);
        if (height(avlTreeP->Right) - height(avlTreeP->Left) == 2)
        {
            if (elementInt > avlTreeP->Right->ElementInt)
            {
                // insert right right, outside of the tree.
                // you should use single rotation to handle it.
                avlTreeP = singleRotationWithRight(avlTreeP);
            }
            else
            {
                // you should use double rotation to handle it.
                avlTreeP = doubleRotationWithRight(avlTreeP);
            }
        }
    }
    // else, element you want to insert has in the tree, you should do nothing.
    // update the heigh attribute.
    avlTreeP->Height = max(height(avlTreeP->Left), height(avlTreeP->Right)) + 1;
    return avlTreeP;
}