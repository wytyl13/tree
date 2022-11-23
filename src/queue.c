/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-18 10:42:49
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-18 10:42:49
 * @Description: this is the implementation file about queue.h
***********************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/queue.h"


void initQueue(LinkQueueP linkQueueP) 
{
    // pointer front and rear pointing to the same address
    linkQueueP->front = linkQueueP->rear \
    = (LinkNodeP)malloc(sizeof(LinkNode));

    // init the front pointer, define its next pointer used null.
    linkQueueP->front->next = NULL;
}

// you should pass the object linkQueue here, but we will not define 
// it, so we used struct pointer instead.
bool isEmpty(LinkQueueP linkQueueP) 
{
    // the linkQueue is empty if rear == front
    return (linkQueueP->front == linkQueueP->rear);
}

bool enQueue(LinkQueueP linkQueueP, ElementType element) 
{
    // you should init a LinkNode struct
    // and define it used the param element
    // then let the struct enter queue
    // you should define the s->next = null, because the s is queue tail.
    LinkNodeP s = (LinkNodeP)malloc(sizeof(LinkNode));
    s->data = element;
    s->next = NULL;

    // description queue
    /*  
    generally. then you should filter the condition, empty
    generally. the enter linkNode is both queue head and queue tail.
    but in this file, we used a null LinkNode pointer as the queue head. so we need not to consider this problem
    the rear is the tail of queue, pointing the current enter queue linkNode
    the rear.next pointer pointing to null before entering queue.
    the s is the LinkNode you defined used param element.
    the rear pointer will ++ after entering queue.
    the current linkNode that rear pointer pointing, its next pointer should point to s.
    then you should move this rear pointer, because you have entered one linkNode
    */

    linkQueueP->rear->next = s;
    linkQueueP->rear = s;

    // because the queue is unlimited, so you need not to judge if it is full.
    // and you need not to judge if the queue is empty.
    return true;
}

bool delQueue(LinkQueueP linkQueueP, ElementTypeP elementP) 
{
    // you should judge if the queue is empty
    if (isEmpty(linkQueueP))
    {
        return false;
    }
    LinkNodeP p = linkQueueP->front->next;
    // if you want to get the deleted data, this code will be useful.
    // elmentP is a outgoing param here.
    *elementP = p->data;
    linkQueueP->front->next = p->next;

    // you should judge if the queue is empty after deleting queue.
    // the p pointer is the node that will be droped.
    // if it is euqal to the rear pointer, it means the queue will be empty if this function success do.
    // so you should define the front pointer equal to rear pointer.
    // if it is not happend, you should do nothing.
    if (p == linkQueueP->rear)
    {
        linkQueueP->front = linkQueueP->rear;
    }
    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
    return true;
}