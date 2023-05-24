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
    sleep(1);
    return rand() % 900000 + 100000;
}
int AOTask2(void *data)
{
    int number = (int)data;
    printf("%d\n",number);
    if(isPrime(number))
        printf("true\n");
    else
        printf("false\n");
    return number+11;
}
int AOTask3(void *data)
{
    int number = (int)data;
    printf("%d\n",number);

    if(isPrime(number))
        printf("true\n");
    else
        printf("false\n");
    return number-13;
}
int AOTask4(void *data)
{
    int number = (int)data;
    printf("%d\n",number);
    number+=2;
    printf("%d\n",number);

    return 0;
}
