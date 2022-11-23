
/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-17 15:57:26
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-17 15:57:26
 * @Description: notice, if you want to inheritence one class, you should use
 * c++, of course, c language has no inheritence, c language just has the include.
 * and the heritence is usually used in business processing program.
 * so if your work will not involve it, you should use c language. because the benefits
 * that c++ gives will be little and the language will be complex if you need not.
 * then, c language usually use the head file, you can define the varibale and struct in it.
 * and include this head file in the c file. that's all, simple and stable.
 * and this head file will be physical merger with c file during the preprocessing stage.
 * we will define the binary tree node in this head file that we have defined in tree_main.c file.
 * but because we would code many utils, it just like we will use many datastructures and struct
 * in main process, so we should separate header file and the implementation file.
 * just like you should have head directory and implementation directory. and has a main c file, it is 
 * the entry function. so we will just define the expression relevant struct.
 * the method about expression calculate
 *      first, you should transform from inorder expression to postfix expression
 *      then, you should transform from postfix expression to expression tree. it is a binary tree.
 *      last, you will get the result value once the step 2 successfully.
***********************************************************************/

#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include <stdbool.h>
#include "stack.h"
#include "queue.h"
// judge the number
bool isNumber(char a);
// judge the char read from expression, whether need to enter stack
int judgeEnStack(SqStackP stack, char ch);

// change the string from inorder expression to postfix expression, 
// you should use char, because has not string class in c language.
LinkQueueP change(char *str);

// define a function that can echo all the elements in a queue.
void printQueue(LinkQueueP linkQueueP);

#endif
