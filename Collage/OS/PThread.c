#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *func(void* var)
{
    char* msg = (char*) var;

    int  i;

    for (int i = 0; i < 5; i++)
    {
        printf("%d %s\n", i, msg);
        sleep(2);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    char* msg1 = "First Thread";
    char* msg2 = "Second Thread";

    int res1, res2;

    res1 = pthread_create(&t1, NULL, func, (void*) msg1);
    res2 = pthread_create(&t2, NULL, func, (void*) msg2);

    printf("Main func after pthread_create\n");
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("first thread res1 = %d\n", res1);
    printf("second thread res1 = %d\n", res2);

    return 0;
}