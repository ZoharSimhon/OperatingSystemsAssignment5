#include "helperFunctions.h"
#include "Queue.h"
#include "ActiveObject.h"

int isPrime(int num)
{
    for (size_t i = 2; i * i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int AOTask1(void *data)
{
    int randomNumber = rand() % 900000 + 100000;
    printf("%d\n",randomNumber);
    return NULL;
}
int AOTask2(void *pao)
{
    pActiveObject this = (pActiveObject)pao;

    return NULL;
}
int AOTask3(void *pao)
{
    pActiveObject this = (pActiveObject)pao;

    return NULL;
}
int AOTask4(void *pao)
{
    pActiveObject this = (pActiveObject)pao;

    return NULL;
}
