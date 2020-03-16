#include <stdio.h>
#include "lambda.h"
#include "foreachinarray.h"

typedef struct __test
{
    int a;
    int b;
} test_t;

void printout (int count, const test_t * arr)
{
    for (int i=0; i<count; ++i)
    {
        printf("%d %d\n", arr[i].a, arr[i].b);
    }
    printf("\n");
}

int main ()
{
    test_t arr[] = { {0, 1}, {2, 3}, {4, 5} };
    printout (sizeof arr / sizeof arr[0], arr);
    forEachInArray
    (
        test_t,
        arr,
        lambda
        (
            test_t,
            (void *item),
            {
                int t = (*(test_t*) item).a;
                (*(test_t*)item).a = (*(test_t*)item).b;
                (*(test_t*)item).b = t;
                return (*(test_t*)item);
            }
        )
    );
    printout (sizeof arr / sizeof arr[0], arr);
    return 0;
}
