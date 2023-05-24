#include "helperFunctions.h"
#include "Queue.h"
#include "ActiveObject.h"

int main(int argc, char *argv[])
{

    if ((argc < 2) || (argc > 3))
    {
        printf("usage: ./st_pipline N <SEED>\n");
        exit(1);
    }

    int N = atoi(argv[1]);
    size_t seed;
    if (argc == 2)
    {
        seed = time(NULL);
    }
    else
    {
        seed = atoi(argv[2]);
    }

    srand(seed);

    pActiveObject pao1 = CreateActiveObject(AOTask1, N);
    // for(size_t i=0; i<N; i++){
    //     enqueue(pao1->queue,(void*)i);
    // }
    // pActiveObject pao2 = CreateActiveObject(AOTask2, N);
    // pActiveObject pao3 = CreateActiveObject(AOTask3, N);
    // pActiveObject pao4 = CreateActiveObject(AOTask4, N);

    // pao1->next = pao2;
    // pao2->next = pao3;
    // pao3->next = pao4;

    while (1)
    {
        sleep(1);
        if (!pao1->N)
        // if (!pao1->N && !pao2->N && !pao3->N && !pao4->N)
        {
            stop(pao1);
            // stop(pao2);
            // stop(pao3);
            // stop(pao4);
            break;
        }
    }
    return 0;
}