#include "../inc/tree.h"
/**
 * @Author: weiyutao
 * @Date: 2022-11-22 13:12:16
 * @Parameters: 
 * @Return: 
 * @Description: we usually init the char used '0'. int the char[20] used {0};
 * init the int used 0; we uded param to init the Element of TreeP.
 */
void initBinaryTree(TreeP treeP, ElementType element) 
{
    treeP->Element = element;
    treeP->Left = (TreeP)malloc(sizeof(Tree));
    treeP->Right = (TreeP)malloc(sizeof(Tree));
}

// this function will general a expression tree. we can use
// after sequence traversal method to get the inorder expression.
// the original expression is inorder. we used postfix just because it is
// simple to transform from expression to expression tree.
TreeP transformTree(LinkQueueP linkQueueP)
{
    // you should init a stack first.because this stack will be
    // dedicated to this function, so we can define an object not a 
    // pointer.
    SqStackTree stackTree;
    initStackTree(&stackTree);
    ElementType element;
    // you should define a pointer to store TreeP.
    TreeP pointer = NULL;
    TreeP treeP = NULL;
    while (delQueue(linkQueueP, &element))
    {
        treeP = (TreeP)malloc(sizeof(Tree));
        initBinaryTree(treeP, element);
        if (element >= 'a' && element <= 'z')
        {
            // init tree node to store the number and push this node into stack
            // but we must define the treeNode for each element.
            // so you must define the treeNode in initTree function.
            pushTree(&stackTree, treeP);

        }
        else
        {
            // create treeNode, pop and define the right child
            // pop and define the left child. notice the sequence.
            // the right child should point to first pop pointer.
            // the left child should point to second pop pointer.
            // push the treeNode.
            // abc+*d-e/
            // you will get all void type pointer in stackTree.
            // but you has pop all void type pointer unless the last element.
            // so the last pointer in stack is void type and it is the root BinaryTree.
            // you can traversal all element in expression tree used the root BinaryTree.
            // and the last, treeP is a void type pointer, because you add it onto tree.
            // it has cast to void type in push function. so you can return this root used void *
            // or return this root used TreeP but you should cast first.
            // notice, this function popTree will return void type pointer
            // if you want use it, you should cast first.
            // init the pointer.
            pointer = (TreeP)getTopTree(&stackTree);
            popTree(&stackTree, pointer);
            treeP->Right = pointer;
            pointer = (TreeP)getTopTree(&stackTree);
            popTree(&stackTree, pointer);
            treeP->Left = pointer;
            pushTree(&stackTree, treeP);

        }
    }
    // transform from void * to TreeP
    return (TreeP)treeP;
}

void preOrderTraversal(TreeP root, int depth) 
{
    if (root)
    {
        printf("%c", root->Element);
        preOrderTraversal(root->Left, depth + 1);
        preOrderTraversal(root->Right, depth + 1);
    }
    
}

void postOrderTraversal(TreeP root, int depth) 
{
    if (root)
    {
        postOrderTraversal(root->Left, depth + 1);
        postOrderTraversal(root->Right, depth + 1);
        printf("%c", root->Element);       
    }
}

void inOrderTraversal(TreeP root, int depth) 
{
    if (root)
    {
        inOrderTraversal(root->Left, depth + 1);
        printf("%c", root->Element);
        inOrderTraversal(root->Right, depth + 1);
    }
}



