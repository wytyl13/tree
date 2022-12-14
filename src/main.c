/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-17 10:00:21
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-17 10:00:21
 * @Description: this file will descripe the tree data structure
 * reference: data structure and algorithm, c language, author: Mark Allen Weiss
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "../inc/stack.h"
#include "../inc/queue.h"
#include "../inc/expression.h"
#include "../inc/tree.h"
#include "../inc/searchTree.h"
#include "../inc/AVLTree.h"
#include "../inc/hash_table.h"
// // define the list.h head file in this file.

/* #ifndef _LIST_H
typedef int ElementType;
typedef struct OriginalTreeNode *PtrToNode;
typedef struct BianryTreeNode *Tree;
#endif
*/

// <<<<<<<<<<<<<<<<<<the implementation file.
/**
define the original TreeNode, involved element, a pointer pointing to the firstChild,
a pointer pointing to the next brother. from left to right.
because the original tree can own many childs, so we can just 
define a pointer pointing to the first child, and define a pointer 
pointing to the next brother. because the efficient will be badly if
one node has many childs. but the binary tree will not has this problem.

the original tree define.
struct OriginalTreeNode
{
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};

the tree node has defined, then we should know the application
it is usually used for the directory structure of operating system.
we will do it later, now we will learn the binary tree first.


binary tree is a tree, and the childs of each node
can not be greater than 2. you should notice the badly binary tree
and original bianry tree. the original bianry tree means eacho node has
two childs, and the badly is each node has 1 child. the highest will
be if the badly happpend. because binary just has as much as two childs,
so we can define two pointer in one node, one pointer pointing the first child,
the other pointer pointing to the other child.

define the binary tree. involved left child pointer and right child pointer.
notice, N nodes bianry tree has N+1 null pointer. these null pointer  are all 
generated by leaf nodes.
struct BinaryTreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
};
*/



// the application of binary tree is expression tree.
/**
you can consider it as all the calculate number will be on leaf node, 
and all operator will be on the tree nodes. and the expression will be
broken down a ? b. so it must be a binary tree.
the way of traverse about expression tree is important.
involved three methods,
first, inorder traversal. left, node, right.
second, postorder traversal, left, right, node
third, preorder traversal, node, left, right
just like the expression tree as follow

            +

    +                           *    
a       *               
    b       c           +           g
                    *       f
                d       e   

the inorder traversal.
    a+b*c+d*e+f*g
    if the next operator priority is greater. you should
    use () involved the operation of the front.
    left: (a+b*c)
    right:(d*e+f)*g
    left+right = (a+b*c) + ((d*e+f)*g)
the postorder traversal
    abc*+de*f+g*+
the preorder traversal
    ++a*bc*+*defg

then we will generate the expression tree used postfix expression
it means we will do how to transform from postfix expression to expression tree.
then we have known, the normal expression is infix expression, 
just like a+b+c*d....
then it will be complex if we calculate it directly.
so we can transform it to expression tree first. then traverse this tree.
the result will be the calculate value if the traversal complete.
but the basic is transform from postfix expression to expression tree.
so we will start with it.
the important concept is used stack as the mediation.
just like abc*+de*f+g*+
step1 you should push numbers into stack unless meet the operator.
step2 you should calculate the last two numbers used operator if you meet the operator.
    it means you should pop twice once you meet operator, and you should
    use the operator you meet as root node, and the last1 number as right child,
    the last2 number as left child.
step3 then, the stack will store numbers address or root address.
    if the last two is root address, the last1 is right child, the last2 is left child.

then we will transform the postfix expression abc*+de*f+g*+ to expression tree.
notice, all operation content for stack will all be the pointer.
and the stack top is left, stack bottom is right
notice the sequence for stack
abc*+de*f+g*+
step1
    meet abc,
    cba -push-> stack
        numbers abc push into stack

    the stack state cba
    the expression tree state.
        null
step2
    meet *,
    cb  -pop-> stack
        cb pop
    *->left child = b
    *->right child = c
    *  -push-> stack
        operator * push into stack as root node

    the stack state, *a
    the expression tree state.
        *
    b       c
step3 
    meet +,
    *a -pop-> stack
        *c pop
    +->left child = a
    +->right child = *.
    + -push-> stack
    the stack state, +
    the expression tree state.
            +
        a       *
            b       c
step4
    meet de
    ed -push-> stack
        ed push
    
    the stack state, ed+
    the expression tree state is equal to step3
step 5
    meet *
    ed -pop-> stack
        ed pop
    *->left child = d
    *->right child = e
    * -push-> stack
    
    the stack state, *+
    the expression tree state.
        *                       +
    d       e               a       *
                                b       c
step 6
    meet f
    f -push-> stack

    the stack state f*+
    the expression tree state is equal to step5
step7
    meet +
    f* -pop-> stack
    +->left child = *
    +->right child = f
    + -push-> stack

    the stack state, ++
    the expression tree state.
        +                       +
    *        f              a       *
d       e                       b       c
step8 
    meet g
    g -push-> stack

    ths stack state, g++
    the expression tree state is equal to step7
step9
    meet *
    g+ -pop-> stack
    *->left child = +
    *->right child = g
    * -push-> stack
    
    the stack state, *+
    the expression tree state.
            *                       +
        +       g               a       *
    *       f                       b       c
d       e
step10
    meet +
    *+ -pop-> stack
    +->left child = +
    +->right child = *
    + -push-> stack

    the stack state, +
    the expression tree state.
        +
    +                       *                            
a       *               +       g
    b       c       *       f               
                d       e
this is the expression tree result transformed from postfix expression.
abc*+de*f+g*+
abc*+de*f+g*+

this is the application of expression tree about bianry.
then we will learn the application of binary search trees.
it is normally application for the search of ADT, ADT means abstract data type.
simulate the data you stored used binary tree is int. so this find problem is simple.
the important concept that bianry tree can be binary search tree is 
the each node x in binary tree, its left child value is less than the node value,
its right child value is greater than node value. just like the follow.
the left is binary search tree, the right is original binary tree.
because the root node [6] is less than its left child node [7].
        6                           [6]
    2       8                   2       8
1       4                   1       4
    3                           3       [7]
// <<<<<<<<<<<<<<<<<the implementation file.
*/


// test stack
// you should malloc this pointer, or you will get segmentation fault.
void test_stack() 
{
    SqStackP stack = (SqStackP)malloc(sizeof(SqStack));
    initStack(stack);
    ElementType a = '1';
    bool flag = push(stack, a);
    printf("%d\n", flag);
    freePointer(stack);
}

void test_queue() 
{
    LinkQueueP linkQueueP;
    linkQueueP = (LinkQueueP)malloc(sizeof(LinkQueue));
    initQueue(linkQueueP);
    bool flag = isEmpty(linkQueueP);
    ElementType a = '2';
    ElementTypeP b;
    // notice, this poiter type must be initialized
    b = (ElementTypeP)malloc(sizeof(ElementType));
    flag = enQueue(linkQueueP, a);
    flag = delQueue(linkQueueP, b);
    printf("%d, deleted data is %c\n", flag, *b);
    freePointer(linkQueueP);
    freePointer(b);
}

SqStackP test_change(char *str) 
{
    SqStackP stack;
    stack = (SqStackP)malloc(sizeof(SqStack));
    // LinkQueueP linkQueueP;
    // linkQueueP = (LinkQueueP)malloc(sizeof(LinkQueue));
    initStack(stack);
    // initQueue(linkQueueP);

    ElementTypeP p = (ElementTypeP)str;
    ElementType ch;
    while ((ch = *p))
    {
        printf("%c", ch);
        push(stack, ch);
        ++p;
    }
    printf("\n");
    freePointer(p);

    return stack;
}

void test_judgeEnStack(SqStackP stack, char *str) 
{
    ElementType ch;
    char *p = str;
    int n;
    while ((ch = *p))
    {
        n = judgeEnStack(stack, ch);
        printf("%d\t", n);
        ++p;
    }
    printf("\n");
}

LinkQueueP test_expression() 
{
    char str[20] = {"(a*(b+c)-d)/e"};
    LinkQueueP linkQueueP = change(str);
    // printQueue(linkQueueP);
    return linkQueueP;
}

// TreeP test_tree_transform(LinkQueueP linkQueueP) 
// {
//     TreeP treeP = transformTree(linkQueueP);
//     return treeP;
// }

int main(int argc, const char *argv[])
{
    // test---------------------------------------------------------
    // char str[20] = {"a+b*c+(d-e)"};
    // // SqStack stack;
    // // initStack(&stack);
    // ElementType element;
    // // push(&stack, '*');
    // SqStackP stack = test_change(str);
    // while (pop(stack, &element))
    // {
    //     if (element == '(')
    //     {
    //         printf("%c\t", element);
    //     }
    // }
    // printf("\n");
    // test----------------------------------------------------------
    // -------expression tree test------------
    
    test_stack();
    test_queue();
    LinkQueueP linkQueueP = test_expression();
    // printQueue(linkQueueP);
    // abc+*d-e/
    TreeP treeP = transformTree(linkQueueP);
    // printf("%c\n", treeP->Right->Right->Left->Right->Element);
    preOrderTraversal(treeP, 0); // /-*a+bcde
    printf("\n");

    inOrderTraversal(treeP, 0); // a*b+c-d/e
    printf("\n");

    postOrderTraversal(treeP, 0); // abc+*d-e/
    printf("\n");
    freePointer(linkQueueP);
    // notice, you should not free the root pointer directly
    // you should free all pointer used this root, then you can free the root
    // here you should use the recursive method.
    // freePointer(treeP);

    // clear this expression tree
    // notice, this function used recursive method to free all pointer in this expression tree,
    // and the address that freed pointer pointing to is also exist. just the content of this address is droped.
    // so you can get the address that the root pointer point, but the content is not exist.
    clearTree(treeP);
    printf("%c\n", treeP->Element);
    // -------expression tree test------------

    // -------searchTree test------------
    SearchTreeP searchTreeP = NULL;
    searchTreeP = insert(searchTreeP, 1);
    searchTreeP = insert(searchTreeP, 2);
    searchTreeP = insert(searchTreeP, 3);
    searchTreeP = insert(searchTreeP, 4);
    searchTreeP = insert(searchTreeP, 5);
    searchTreeP = insert(searchTreeP, 6);
    searchTreeP = insert(searchTreeP, 7);
    printf("%d\n",searchTreeP->ElementInt);
    inOrderSearchTree(searchTreeP, 0);
    printf("\n"); //012354
    preOrderSearchTree(searchTreeP, 0);
    printf("\n"); // 102354
    postOrderSearchTree(searchTreeP, 0);
    printf("\n"); // 023541

    makeEmpty(searchTreeP);
    // printf("%d\n", searchTreeP->Left->ElementInt); return error content. because the address is clear.
    // 97 page
    // ------------searchTree test------------

    // ------------AVL tree test------------
    AvlTreeP avlTreeP = NULL;
    // notice, because the height is static function, so you can not use it here.
    // printf("%d\n", height(avlTreeP));
    // avlTreeP = insertAvl(avlTreeP, 1);
    avlTreeP = insertAvl(avlTreeP, 2);
    avlTreeP = insertAvl(avlTreeP, 4);
    avlTreeP = insertAvl(avlTreeP, 5);
    avlTreeP = insertAvl(avlTreeP, 6);
    avlTreeP = insertAvl(avlTreeP, 7);
    // avlTreeP = insertAvl(avlTreeP, 3);
    // avlTreeP = insertAvl(avlTreeP, 8);
    // avlTreeP = insertAvl(avlTreeP, 9);
    // avlTreeP = insertAvl(avlTreeP, 10);
    printf("%d\n", avlTreeP->ElementInt);
    printf("%d\n", avlTreeP->Left->ElementInt);
    printf("%d\n", avlTreeP->Right->ElementInt);
    // printf("%d\n", avlTreeP->Left->Left->ElementInt);
    // printf("%d\n", avlTreeP->Left->Right->ElementInt);
    // printf("%d\n", avlTreeP->Right->Left->ElementInt);
    // printf("%d\n", avlTreeP->Right->Right->ElementInt);
    // preOrderAvlTree(avlTreeP, 0);
    // printf("\n");
    // inOrderAvlTree(avlTreeP, 0);
    // printf("\n");
    // postOrderAvlTree(avlTreeP, 0);
    // printf("\n");
    // printf("%d\n", avlTreeP->Height);
    // printf("%d\n", height_recursive_call(avlTreeP));
    // printf("%d\n", height_recursive_call_used_pointer(avlTreeP));
    // page108 splay tree.
    // omit the splay tree.
    // ------------AVL tree test------------

    // ------------B tree test------------
    
    // ------------B tree test------------



    // ------------hash table test------------
    const char key[] = "wo1ini";
    Index index_ascii = hash_ascii(key, 10007);
    printf("the return index_ascii is %u\n", index_ascii);

    Index index_alphabet = hash_alphabet(key, 10007);
    printf("the return index_alphabet is %u\n", index_alphabet);

    Index index = hash(key, 10007);
    printf("the return index is %u\n", index);
    // ------------hash table test------------


    return 0;
}
