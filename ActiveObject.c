#include "ActiveObject.h"

void* activate(void* this)
{
    pActiveObject pao = (pActiveObject)this;
    void *data;
    size_t counter = 0;
    while (1)
    {
        data = dequeue(pao->queue);
        if (pao->func != NULL)
        {
            pao->func(data);
        }
        counter++;

        // if counter == N
    }
    return NULL;
}

pActiveObject CreateActiveObject(void(func)(void *), size_t N)
{
    pActiveObject this = (pActiveObject)malloc(sizeof(ActiveObject));
    if (this == NULL)
    {
        perror("malloc");
        exit(1);
    }

    this->queue = createQueue();
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
    {
        perror("calloc thread");
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
    pthread_cancel(*this->thread);
    destoryQueue(this->queue);
    free(this);
}

void print(void *data)
{
    printf("%p\n", data);
}