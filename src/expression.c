/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-18 15:36:18
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-18 15:36:18
 * @Description: the implement file for expression.h
 * this file should involve transform from inorder expression to postfix expression.
 * then you should calculate the postfix expression used stack, the rule about
 * calculate used the concept of tree. so this rule is tree, this tool is stack.
***********************************************************************/
#include "../inc/expression.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
bool isNumber(char a) 
{
    if (a >= '0' && a <= '9')
    {
        return true;
    }
    return false;
}

/**
 * @Author: weiyutao
 * @Date: 2022-11-18 16:39:20
 * @Parameters: 
 * @Return: -1: enter queue. 0:  pop and enter queue util != 0, then push ch.
 * 1: push stack. 2: pop and enterqueue util meet '('. and drop '()'.
 * @Description: judge the char, whether need to enter stack
 * the rule:
 *      number output directly.
 *      if meet operator,
 *          if right parenthesis
 *              pop util meet left parenthesis
 *                  pop left parenthesis but not echo
 *          if left parenthesis
 *              push
 *          if other operator
 *              pop util meet the lower operator, then push this operator
 *      if read \0, it mean read null
 *          pop all element
 * implementation
 *      the concept, you should enterqueue direct if you meet number.
 *      if it is greater than the stack top element if you meet an operator, pop util meet a element that less than it.
 *      the stack just stored the operator and "()"
 *      you should pop util meet "(" if you meet ")", and the "(" only pop not enter queue.
 *      if you read null, you should pop all element in stack and enter queue if the stack is not empty.
 *      last, you should print the queue, it will be the result.
 *  
 *      the simple situaton:
 *          if the stack is empty, the situation is simple, you should enterqueue the ch if it is equal to numbers.
 *          you should push the ch it is not numbers. we used a-z to store the numbers in this file.
 *      other situation, the complex situation.
 *          if ch == 'a-z', a-z means number here, 
 *              return -1; enter queue directly.
 *          if ch == '+' and temp == +-* or divide
 *              this situation can represent that meet a operator and this operator is greater than the stack top.
 *              it means the current operator is greater than top stack. so you should push.
 *              else, if the current operator is less or euqal to top stack, you should pop and enterqueue first, and then push the current operator.
 *              notice, here is less or equal to top stack.
 *          if meet '('
 *              push directly
 *          if meet ')'
 *              pop and enterqueue util meet '(' and the '(' only pop not enterqueue. the '(' droped.
 *          if ch=''
 *              pop all element and enterqueue
 *          last delQueue. it is the result.
 */
int judgeEnStack(SqStackP stack, ElementType ch) 
{
    // get stack top element
    ElementType temp = getTop(stack);


    // return 1, enter queque directly.
    if (ch >= 'a' && ch <= 'z')
    {
        return -1;
    }

    // return 0, the current operator is less or equal to top stack.
    // pop and enterqueue, then push the current operator.
    else if (ch == '+' && (temp == '+' || temp == '-' || temp == '*' || temp == '/'))
    {
        return 0;
    }
    else if (ch == '-' && (temp == '+' || temp == '-' || temp == '*' || temp == '/'))
    {
        return 0;
    }
    else if (ch == '*' && (temp == '*' || temp == '/'))
    {
        return 0;
    }
    else if (ch == '/' && (temp == '*' || temp == '/'))
    {
        return 0;
    }
    // return 2, meet ')', pop and enterqueue util meet '('
    else if (ch == ')')
    {
        return 2;
    }
    else
    {
        // meet '(' , meet operator and top stack is '('
        // because the current must be operator or '(' at here.
        // meet '(', push stack.
        // meet operator and top stack is '(', push stack.
        // meet operator and it is greater than top stack. push stack.
        return 1;
    }
}

/**
 * @Author: weiyutao
 * @Date: 2022-11-20 09:47:37
 * @Parameters: 
 * @Return: 
 * @Description: this function can change the expression, involved a-z and operator, from 
 * inorder expression to postfix expression. this function used stack and queue as tool to transform
 * from inorder expression to postficx expression. then we will used tree to do it. we can used binary
 * show method, just like before the sequence tranversal to represent inorder expression, used after the sequence
 * tranversal to represent postfix expression. we have not used postfix expression to calculate the expression yet.
 * 
 */
LinkQueueP change(char *str) 
{
    // init the stack and queue
    SqStackP stack;
    LinkQueueP linkQueueP;
    stack = (SqStackP)malloc(sizeof(SqStack));
    linkQueueP = (LinkQueueP)malloc(sizeof(LinkQueue));
    initStack(stack);
    initQueue(linkQueueP);

    ElementType ch, topStack;
    // you need define a pointer pointing to the str param.
    // because you can not move this pointer str.
    char *p = str;
    int n;

    while ((ch = (ElementType)*p))
    {
        // ignore the space
        if (ch == ' ')
        {
            ++p;
            continue;
        }
        // if stack is empty
        if (emptyStack(stack))
        {
            // if ch is a-z, enter queue directly
            if (ch >= 'a' && ch <= 'z')
            {
                enQueue(linkQueueP, ch);
            }
            else
            {
                push(stack, ch);
            }
        }
        else
        {
            n = judgeEnStack(stack, ch);
            if (n == -1)
            {
                enQueue(linkQueueP, ch);
            }else if (n == 0)
            {
                while (1)
                {
                    // pop
                    pop(stack, &topStack);
                    // enter queue
                    enQueue(linkQueueP, topStack);
                    // get the ch again and compare the priority
                    if (emptyStack(stack) || (judgeEnStack(stack, ch) != 0))
                    {
                        push(stack, ch);
                        break;
                    }
                }
            }
            else if (n == 2)
            {
                // pop and enQueue util meet "(", it means "(" only pop but not enQueue
                // because the () just a rule not the expression. so this result should not involved ()
                while (1)
                {
                    pop(stack, &topStack);
                    if (topStack == '(')
                    {
                        break;
                    }
                    else
                    {
                        // enQueue
                        enQueue(linkQueueP, topStack);
                    }
                }
            }
            else if (n == 1)
            {
                // while (1)
                // {
                //     pop(stack, &topStack);
                //     enQueue(linkQueueP, topStack);
                //     if (emptyStack(stack) || (judgeEnStack(stack, ch) != 1))
                //     {
                //         break;
                //     }
                // }
                push(stack, ch);
            }
            // else
            // {
            //     // other situation, enter queue directly.
            //     enQueue(linkQueueP, ch);
            // }
        }
        ++p;
    }

    while (!emptyStack(stack))
    {
        // all element pop and enter queue
        pop(stack, &topStack);
        enQueue(linkQueueP, topStack);
    }
    return linkQueueP;
}

void printQueue(LinkQueueP linkQueueP) 
{
    ElementTypeP elementP;
    elementP = (ElementTypeP)malloc(sizeof(ElementType));
    while (!isEmpty(linkQueueP))
    {
        delQueue(linkQueueP, elementP);
        printf("%c", *elementP);
    }
    printf("\n");
}
