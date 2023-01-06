/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-18 10:31:11
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-18 10:31:11
 * @Description: this file, we will define a link.
 * because this file is the original file, so we will
 * define some function that the commonly used in this file.
***********************************************************************/
#ifndef _LINK_H
#define _LINK_H
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char ElementType, *ElementTypeP;
typedef int ElementIntType, *ElementIntTypeP;
struct Node;
typedef struct Node LinkNode, *LinkNodeP;
struct Node
{
    ElementType data;
    LinkNodeP next;
};

// add the listNode that hash table used.
// but we should notice, if we define the listNode at here, the cross reference
// will happen. because the struct ListNode used Position, and the struct
// Positon used LinkNode. so the compilation fails will be happen.
// so we should consider define the listNode in the head file of hash table.
struct ListNode;
typedef struct ListNode *Position;
struct ListNode
{
    ElementType element;
    Position Next;
};

// sys error
void
sysError(const char *str);
// free the pointer
void freePointer(void *pointer);
#endif
