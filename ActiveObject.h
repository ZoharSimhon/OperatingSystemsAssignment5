#pragma once

#include "Queue.h"

typedef struct _ActiveObject
{
    pthread_t *thread;
    pQueue queue;
    void (*func)(void *);
    struct _ActiveObject *next;
    size_t N;
} ActiveObject, *pActiveObject;

pActiveObject CreateActiveObject(void(func)(void *), size_t N);

pQueue getQueue(pActiveObject this);

void stop(pActiveObject this);

void *activate(void *this);
