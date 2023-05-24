#include "ActiveObject.h"

void activate(pActiveObject this)
{
    void *data;
    size_t counter = 0;
    while (data = dequeue(this->queue))
    {
        if (this->func != NULL)
        {
            this->func(data);
        }
        counter++;

        // if counter == N
    }
}

pActiveObject CreateActiveObject(pQueue queue, void(func)(void *), size_t N)
{
    pActiveObject this = (pActiveObject)malloc(sizeof(ActiveObject));
    if (this == NULL)
    {
        perror("malloc");
        exit(1);
    }

    this->queue = queue;
    this->func = func;
    this->N = N;
    this->next = NULL;
    this->thread = (pthread_t *)calloc(1, sizeof(pthread_t));
    if (this->thread == NULL)
    {
        perror("calloc thread");
        free(this);
        exit(1);
    }

    // start thread
    if (pthread_create(pReactor->thread, NULL, activate, this) != 0)
    {
        perror("pthread_create");
    }

    return this;
}

pQueue getQueue(pActiveObject this)
{
    return activeObject->queue;
}

void stop(pActiveObject this)
{
    pthread_cancel(this->thread);
    destoryQueue(this->queue);
    free(this);
}
