#ifndef BOOTSTRAP
#define BOOTSTRAP

#define EXPONENTIAL_INCREMENT_BASE 2
#define EXPONENTIAL_INCREMENT_STEPS 7
#define EXPONENTIAL_INCREMENT_START 500

#define REPETITIONS_IF_UNTRUSTED_TIME 1000

// Arg init
void init_rand_seed();
void rand_fill_int(int v[], int n);
// Timing
double get_micro_seconds();
// Printing
// TODO Add table print or similar
void print_vector_int(int v[], int n);
void print_vector_double(double v[], int n);



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

#endif
