#pragma once

#include "Queue.h"

// define the struct
typedef struct _ActiveObject
{
    pthread_t *thread;
    pQueue queue;
    int (*func)(void *);
    struct _ActiveObject *next;
    size_t N;
} ActiveObject, *pActiveObject;

pActiveObject CreateActiveObject(void(func)(void *), pActiveObject next, size_t N);

pQueue getQueue(pActiveObject this);

void stop(pActiveObject this);

void *activate(void *this);