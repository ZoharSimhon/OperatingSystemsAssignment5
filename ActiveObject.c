#include "ActiveObject.h"
#include "helperFunctions.h"

void *activate(void *this)
{
    //casting this to pActiveObject
    pActiveObject pao = (pActiveObject)this;
    void *data;
    int result;
    int done = 0;
    //while we didn't check all the elements
    while (!done)
    {
        //if we are in the first task, so we don't need to dequeue elements
        if (pao->func != AOTask1)
            data = dequeue(pao->queue);
        //send the data to the function
        if (pao->func != NULL)
        {
            result = pao->func(data);
            if (pao->next)
                enqueue(pao->next->queue, (void *)result);
        }
        pao->N--;

        //if we done check all the data
        if (0 == pao->N)
            done=1;
    }
    return NULL;
}

pActiveObject CreateActiveObject(void(func)(void *), size_t N)
{
    pActiveObject this = (pActiveObject)malloc(sizeof(ActiveObject));
    //if the malloc didn't succeed
    if (this == NULL)
    {
        perror("malloc");
        exit(1);
    }

    this->queue = createQueue();
    //if the malloc didn't succeed - free all the data
    if (this->queue == NULL)
    {
        perror("createQueue");
        free(this);
        exit(1);
    }

    this->func = func;
    this->N = N;
    this->next = NULL;
    this->thread = (pthread_t *)calloc(1, sizeof(pthread_t));
    if (this->thread == NULL)
    //if the malloc didn't succeed - free all the data
    {
        perror("calloc thread");
        destoryQueue(this->queue);
        free(this);
        exit(1);
    }

    // start thread
    if (pthread_create(this->thread, NULL, activate, this) != 0)
    {
        perror("pthread_create");
    }

    return this;
}

pQueue getQueue(pActiveObject this)
{
    return this->queue;
}

void stop(pActiveObject this)
{
    //cancel the thread
    pthread_cancel(*this->thread);
    //free the queue
    destoryQueue(this->queue);
    //free the pActiveObject
    free(this);
}
