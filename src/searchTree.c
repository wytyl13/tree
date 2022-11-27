#include "../inc/searchTree.h"

SearchTreeP makeEmpty(SearchTreeP searchTreeP) 
{
    if (searchTreeP)
    {
        makeEmpty(searchTreeP->Left);
        makeEmpty(searchTreeP->Right);
        freePointer(searchTreeP);
    }
    return NULL;
}

SearchTreeP find(SearchTreeP searchTreeP, ElementIntType elementInt) 
{
    if (searchTreeP == NULL)
    {
        return NULL;
    }
    // if this number you find is less than the root number
    // you should move to left child and go on.
    // else you should move to right and go on.
    // notice, because this recursive function used the child node of root tree
    // so we can not use the void *param to accept the root.
    // this is because we do not have defined a void element for the tree
    // defined two tree, on store the char, one store the int. we can change the element to void.
    // if we have defined it, we can cast the void * to treeP, then we can define a general
    // function to init and find the element.
    // but this function is also dedicated to the int element. because the search tree
    // is original the int element. if not, it will be meaningless!
    if (elementInt < searchTreeP->ElementInt)
    {
        return find(searchTreeP->Left, elementInt);
    }
    else if (elementInt > searchTreeP->ElementInt)
    {
        return find(searchTreeP->Right, elementInt);
    }
    else
    {
        return searchTreeP;
    }
}

SearchTreeP findMin(SearchTreeP searchTreeP) 
{
    if (searchTreeP == NULL)
    {
        return NULL;
    }
    else if (searchTreeP->Left == NULL)
    {
        return searchTreeP;
    }
    else
    {
        return findMin(searchTreeP->Left);
    }
}

SearchTreeP findMax(SearchTreeP searchTreeP) 
{
    if (searchTreeP == NULL)
    {
        return NULL;
    }
    else if (searchTreeP->Right == NULL)
    {
        return searchTreeP;
    }
    else
    {
        return findMax(searchTreeP->Right);
    }

    // you can also define a nonrecursive method
    // if (searchTreeP != NULL)
    // {
    //     while (searchTreeP->Right != NULL)
    //     {
    //         searchTreeP = searchTreeP->Right;
    //     }
    //     return searchTreeP;
        
    // }
}


/**
 * @Author: weiyutao
 * @Date: 2022-11-27 21:38:51
 * @Parameters: 
 * @Return: 
 * @Description: this insert function is simple case, it has a simple rule.
 * if the insert number is growing, this search tree depth will be very big.
 * it will be inefficient. if you want to define a effective insert function, 
 * you shoud define a complex function.
 */
SearchTreeP insert(SearchTreeP searchTreeP, ElementIntType elementInt) 
{
    if (searchTreeP == NULL)
    {
        searchTreeP = (SearchTreeP)malloc(sizeof(SearchTree));
        // printf("i am here!!!");
        if (searchTreeP == NULL)
        {
            sysError("malloc error!!!");
        }
        else
        {
            searchTreeP->ElementInt = elementInt;
            searchTreeP->Left = searchTreeP->Right = NULL;
            // printf("i am here!!!");
        }
    }
    else if (elementInt < searchTreeP->ElementInt)
    {
        // insert into left
        searchTreeP->Left = insert(searchTreeP->Left, elementInt);
    }
    else if (elementInt > searchTreeP->ElementInt)
    {
        // insert into right
        searchTreeP->Right = insert(searchTreeP->Right, elementInt);
    }
    return searchTreeP;
}

// delete function is the most complex.
// you should consider three main condition.
// first, the deleted node is leaf, delete it direct
// second, the deleted node has one child. you can delete it used link method. 
//you do not have to consider if the left is less than right. because it must comform to the search tree feature.
// third, the deleted node has two child. it is the most complex.
/*
just like the case as follow.
        6       -> delete 2         6
    2       8                   3       8
1       5                   1       5
    3                           4
        4                           
notice the rule 
    first, left child must be less than right child.
    second, left child must be less than the father node.
    third, the father node must be less than the right child.
then, you can get the step about delete.
first, delete two, and the 3 number should be to stead of.
second, the 4 number should be to stead of 3 number.
so we can conclude that, the deleted node must be stead by
the last left child of the deleted node's right child.
and similarly, the position of the stead node should be also stead by 
the last left child of the stead node's right child. and it means you should
use the smallest in right child of this current node to instead the current change node.

it means above, 
    if the deleted node has not child, delete it directly. 
    if the deleted node has one child, use the child node to instead of it, and free it
    if the deleted node has two child, use the smallest node in right child node of this deleted node
    to instead the deleted node, and recursive all changed node.
then we will consider the detail code
first, you should find the deleted node. can we use the function find we have defined? no
        you should use recursive. why? because the efficinet
        you should use the method. if (x < P->element) delete(P, element); recursive to find the deleted node
second, if you have done the step1, you should judge the deleted's child condition.
        if has one child, the deleted address is equal to the right or left node of the deleted node
        if has no child. the deleted address == null.
        if has two child. the delted should be instead by the min node used its right node as root node.
        and you should delete the min node for its right node as root node. the min node of its right node should
        be the left lead of the right node, so you can also use delete function to delete it. but you should
        pass the right node as the root node, and the min node as deleted node for delete function.
*/

SearchTreeP delete (SearchTreeP searchTreeP, ElementIntType elementInt) 
{
    // you should define a temp variable to store the object.
    SearchTreeP tempCell;
    if (searchTreeP == NULL)
    {
        sysError("element not found!");
    }
    else if (elementInt < searchTreeP->ElementInt)
    {
        // first, you should find the deleted node, and you should use recursive method,
        // because you should consider each node that will be changed.
        // recursive and find the deleted node
        // notice, because the delete function will return the new root node.
        // so we should use the current node to accept it.
        // it means, if the deleted function use the right node as root node, you should use the right node to accept it.
        // or you will use the left child node to accept it.
        searchTreeP->Left = delete (searchTreeP->Left, elementInt);
    }
    else if (elementInt > searchTreeP->ElementInt)
    {
        searchTreeP->Right = delete (searchTreeP->Right, elementInt);
    }
    else if (searchTreeP->Left && searchTreeP->Right)
    {
        // has two child
        tempCell = findMin(searchTreeP->Right);
        searchTreeP->ElementInt = tempCell->ElementInt;
        searchTreeP->Right = delete (searchTreeP->Right, tempCell->ElementInt);
    }
    else
    {
        // has one child or has not child.
        tempCell = searchTreeP; // store the deleted node

        // the code follow means, if has one child node is null, you should define
        // the father node is equal to its another child. it is apply to the deleted node 
        // just has one child node and has not child node.
        if (searchTreeP->Left == NULL)
        {
            // just has left child.
            searchTreeP = searchTreeP->Right;
        }
        else if (searchTreeP->Right == NULL)
        {
            searchTreeP = searchTreeP->Left;
        }
        free(tempCell); // free temp node address, notice, it point the deleted address.
    }
    return searchTreeP; // last, you will get the deleted successful root node.
}

void preOrderSearchTree(SearchTreeP searchTreeP, int depth) 
{
    if (searchTreeP)
    {
        printf("%d", searchTreeP->ElementInt);
        preOrderSearchTree(searchTreeP->Left, depth + 1);
        preOrderSearchTree(searchTreeP->Right, depth + 1);
    }
}

void inOrderSearchTree(SearchTreeP searchTreeP, int depth) 
{
    if (searchTreeP)
    {
        preOrderSearchTree(searchTreeP->Left, depth + 1);
        printf("%d", searchTreeP->ElementInt);
        preOrderSearchTree(searchTreeP->Right, depth + 1);
    }
}

void postOrderSearchTree(SearchTreeP searchTreeP, int depth) 
{
    if (searchTreeP)
    {
        preOrderSearchTree(searchTreeP->Left, depth + 1);
        preOrderSearchTree(searchTreeP->Right, depth + 1);
        printf("%d", searchTreeP->ElementInt);
    }
}
