#ifndef BOOTSTRAP
#define BOOTSTRAP

#include <math.h>

#define EXP_INCREMENT_BASE 2
#define EXP_INCREMENT_STEPS 7
#define EXP_INCREMENT_START 500
#define TRUSTED_TIME 500.0

#define LAST_N (int)(EXP_INCREMENT_START * \
                     pow(EXP_INCREMENT_BASE, EXP_INCREMENT_STEPS))

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
/// Toma el tiempo de lo que tenga entre los parentesis
#define time_it$(func) ({        \
    double start, end;           \
    start = get_micro_seconds(); \
    func;                        \
    end = get_micro_seconds();   \
    end - start;                 \
})

/// Repite la ejecución de la función para tomar los tiempos de las funciones demasiado rapidas
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

/// Llama progresivamente con un `n` exponencialmente mayor a lo que tenga entre parentesis
/// El cuerpo tiene acceso implicitamente a:
/// - `int i` el step en el que está
/// - `int n` el tamaño de la `n`
#define exponential_increment$(body) ({       \
    int i;                                    \
    int n = EXP_INCREMENT_START;              \
    for (i = 0; i < EXP_INCREMENT_STEPS; i++) \
    {                                         \
        body;                                 \
        n *= EXP_INCREMENT_BASE;              \
    }                                         \
})
#pragma endregion Util Macros
#endif
