/**********************************************************************
 * Copyright (C) 2022. IEucd Inc. All rights reserved.
 * @Author: weiyutao
 * @Date: 2022-11-18 10:27:53
 * @Last Modified by: weiyutao
 * @Last Modified time: 2022-11-18 10:27:53
 * @Description: this file, we will define a queue used linkNode.
***********************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

#include "link.h"
struct Queue;
typedef struct Queue LinkQueue, *LinkQueueP;

struct Queue
{
    LinkNodeP front, rear;
};
void initQueue(LinkQueueP linkQueueP);
bool isEmpty(LinkQueueP linkQueueP);
bool enQueue(LinkQueueP linkQueueP, ElementType element);
bool delQueue(LinkQueueP linkQueueP, ElementTypeP elementP);


#endif
