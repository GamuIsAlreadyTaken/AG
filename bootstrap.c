#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "bootstrap.h"

void init_rand_seed()
{
    srand(time(NULL));
}

void rand_fill_int(int v[], int n)
{
    int i, m = 2 * n + 1;
    for (i = 0; i < n; i++)
        v[i] = (rand() % m) - n;
}

double get_micro_seconds()
{
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}
#pragma region Util Macros
#define time_it$(func) ({        \
    double start, end;           \
    start = get_micro_seconds(); \
    func;                        \
    end = get_micro_seconds();   \
    end - start;                 \
})

#define time_repeated$(init, func) ({                                         \
    int i;                                                                    \
    double start, end, t_shared, t_extra;                                     \
    t_shared = time_it$(for (i = 0; i < REPETITIONS_IF_UNTRUSTED_TIME; i++) { \
        init;                                                                 \
        func;                                                                 \
    });                                                                       \
    t_extra = time_it$(for (i = 0; i < REPETITIONS_IF_UNTRUSTED_TIME; i++) {  \
        init;                                                                 \
    });                                                                       \
    (t_shared - t_extra) / REPETITIONS_IF_UNTRUSTED_TIME;                     \
})

#define exponential_increment$(body) ({               \
    int i;                                            \
    int n = EXPONENTIAL_INCREMENT_START;              \
    double times[EXPONENTIAL_INCREMENT_STEPS];        \
    for (i = 0; i < EXPONENTIAL_INCREMENT_STEPS; i++) \
    {                                                 \
        body;                                         \
        n *= EXPONENTIAL_INCREMENT_BASE;              \
    }                                                 \
    times;                                            \
})
#pragma endregion Util Macros

void print_vector_int(int v[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
    {
        printf("% d ", v[i]);
    }
    printf("]");
}
void print_vector_double(double v[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++)
    {
        printf("% f ", v[i]);
    }
    printf("]");
}