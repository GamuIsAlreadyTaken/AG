#ifndef BOOTSTRAP
#define BOOTSTRAP

#include <math.h>

#define EXP_INCREMENT_BASE 2
#define EXP_INCREMENT_STEPS 7
#define EXP_INCREMENT_START 500
#define TRUSTED_TIME 500.0

#define LAST_N (int)(EXP_INCREMENT_START * \
                     pow(EXP_INCREMENT_BASE, EXP_INCREMENT_STEPS - 1))

#define REPS_FOR_UNTRUSTFUL_TIME 1000

// Arg init
void init_rand_seed();
void rand_fill_int(int v[], int n);
void asc_fill_int(int v[], int n);
void desc_fill_int(int v[], int n);
// Timing
double get_micro_seconds();
// Printing
void print_table(
    double tiempos[],
    char *f1_name, char *f2_name, char *f3_name,
    double (*f1)(double), double (*f2)(double), double (*f3)(double));

void print_vector_int(int v[], int n);
void print_vector_double(double v[], int n);
/// Toma el tiempo de lo que tenga entre los paréntesis
#define time_it$(func) ({        \
    double start, end;           \
    start = get_micro_seconds(); \
    func;                        \
    end = get_micro_seconds();   \
    end - start;                 \
})

/// Repite la ejecución de la función para tomar los tiempos de las funciones demasiado rápidas
#define time_repeated$(init, func) ({                                    \
    int i;                                                               \
    double t_shared, t_extra;                                            \
    t_shared = time_it$(for (i = 0; i < REPS_FOR_UNTRUSTFUL_TIME; i++) { \
        init;                                                            \
        func;                                                            \
    });                                                                  \
    t_extra = time_it$(for (i = 0; i < REPS_FOR_UNTRUSTFUL_TIME; i++) {  \
        init;                                                            \
    });                                                                  \
    (t_shared - t_extra) / REPS_FOR_UNTRUSTFUL_TIME;                     \
})

/// Llama progresivamente con un `n` exponencialmente mayor a lo que tenga entre paréntesis
/// El cuerpo tiene acceso implícitamente a:
/// - `int i` el step en el que está
/// - `int n`
#define exponential_increment$(body) ({       \
    int i;                                    \
    int n = EXP_INCREMENT_START;              \
    for (i = 0; i < EXP_INCREMENT_STEPS; i++) \
    {                                         \
        body;                                 \
        n *= EXP_INCREMENT_BASE;              \
    }                                         \
})
#endif
