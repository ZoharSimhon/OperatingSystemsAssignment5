#include "helperFunctions.h"
#include "Queue.h"
#include "ActiveObject.h"

int main(int argc, char *argv[])
{
    // check if the arguments are valid
    if ((argc < 2) || (argc > 3))
    {
        printf("usage: ./st_pipline N <SEED>\n");
        exit(1);
    }

    int N = atoi(argv[1]);
    size_t seed;
    if (argc == 2) // if we didn't get seed
    {
        seed = time(NULL);
    }
    else
    {
        seed = atoi(argv[2]);
    }

    srand(seed); // generate seed

    // create four AOs
    pActiveObject pao4 = CreateActiveObject(AOTask4, NULL, N);
    pActiveObject pao3 = CreateActiveObject(AOTask3, pao4, N);
    pActiveObject pao2 = CreateActiveObject(AOTask2, pao3, N);
    pActiveObject pao1 = CreateActiveObject(AOTask1, pao2, N);

    // check every second if the task are done
    while (1)
    {
        sleep(1);
        if (!pao1->N && !pao2->N && !pao3->N && !pao4->N)
        {
            stop(pao1);
            stop(pao2);
            stop(pao3);
            stop(pao4);
            break;
        }
    }
    return 0;
}