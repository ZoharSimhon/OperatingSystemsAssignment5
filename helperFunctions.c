#include "headers.h"

int isPrime(int num){
    for(size_t i =2; i*i<num; i++)
    {
        if(num%i ==0)
            return 0;
    }
    return 1;
}

