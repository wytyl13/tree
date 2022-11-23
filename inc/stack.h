/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-17 16:44:38
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-17 16:44:38
 * @Description: this file we will code a stack used sequence, we 
 * will use array as the data structure of stack. 
***********************************************************************/
#ifndef _STACK_H
#define _STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "link.h"
#include "tree.h"
#define MAXSIZE 88

struct Stack;
typedef struct Stack SqStack, *SqStackP;

// define a void type pointer array. you can store any type pointer
// used it.
struct Stack
{
    ElementType data[MAXSIZE];
    int top; // the stack top flag
};

// because we want to store the address, so we must define a stack to store the address
struct StackTree;
typedef struct StackTree SqStackTree, *SqStackTreeP;

// pointer array and array pointer
// int *a[5]; it is a pointer array, own five element
// int (*a)[5]; it is a array pointer, is a pointer pointing to the anonymous array.
// notice, void can accept any type pointer, but if you want to assignment
// a pointer used it, you should cast the void to the sepecify type pointer.
struct StackTree
{
    // store any type pointer. notice, each pointer in this pointer array
    // are all not init. you should malloc address for it.
    void *data[MAXSIZE];
    int top;
};

// because c language has not the constructor to init the struct
// so we must define the init function out of the struct define.
// and it is usually state the function in head file and
// define the function in implementation c file.
void initStack(SqStackP stack);
bool emptyStack(SqStackP stack);
bool fullStack(SqStackP stack);
bool push(SqStackP stack, ElementType element);
bool pop(SqStackP stack, ElementTypeP elementP);
ElementType getTop(SqStackP stack);

// this stack Tree is just need to define the push pop and getTop function
// init full empty function are be general. but the param will be different
// so you can redefine or change tha param used void *.
void initStackTree(SqStackTreeP stackTree);
bool emptyStackTree(SqStackTreeP stackTree);
bool fullStackTree(SqStackTreeP stackTree);
bool pushTree(SqStackTreeP stackTree, void *pointer);
bool popTree(SqStackTreeP stackTree, void *pointer);
void *getTopTree(SqStackTreeP stackTree);
#endif

