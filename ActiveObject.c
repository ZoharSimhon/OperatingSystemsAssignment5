#include "ActiveObject.h"
#include "helperFunctions.h"

void *activate(void *this)
{
    pActiveObject pao = (pActiveObject)this;
    void *data;
    int result;
    while (1)
    {
        if (pao->func != AOTask1)
            data = dequeue(pao->queue);
        if (pao->func != NULL)
        {
            result = pao->func(data);
            if (pao->next)
                enqueue(pao->next->queue, (void *)result);
        }
        pao->N--;

        if (0 == pao->N)
            break;
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
