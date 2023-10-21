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
void inicializar_semilla();
void aleatorio(int v[], int n);
void ascendente(int v[], int n);
void descendente(int v[], int n);
// Timing
double microsegundos();
// Printing
void print_table(
    double tiempos[],
    char *f1_name, char *f2_name, char *f3_name,
    double (*f1)(double), double (*f2)(double), double (*f3)(double));

void listar_vector(int v[], int n);
void print_vector_double(double v[], int n);

/// Toma el tiempo de lo que tenga entre los paréntesis
#define TIME_IT($body) ({        \
    double start, end;           \
    start = microsegundos(); \
    $body;                       \
    end = microsegundos();   \
    end - start;                 \
})

/// Repite la ejecución de la función para tomar los tiempos de las funciones demasiado rápidas
#define TIME_REPEATED($init, $body) ({                                  \
    int i;                                                              \
    double t_shared, t_extra;                                           \
                                                                        \
    t_shared = TIME_IT(for (i = 0; i < REPS_FOR_UNTRUSTFUL_TIME; i++) { \
        $init;                                                          \
        $body;                                                          \
    });                                                                 \
                                                                        \
    t_extra = TIME_IT(for (i = 0; i < REPS_FOR_UNTRUSTFUL_TIME; i++) {  \
        $init;                                                          \
    });                                                                 \
                                                                        \
    (t_shared - t_extra) / REPS_FOR_UNTRUSTFUL_TIME;                    \
})

/// Llama progresivamente con un `n` exponencialmente mayor a lo que tenga entre paréntesis
/// El cuerpo tiene acceso implícitamente a:
/// - `int i` el step en el que está
/// - `int n`
#define EXPONENTIAL_INCREMENT($body) ({       \
    int i;                                    \
    int n = EXP_INCREMENT_START;              \
                                              \
    for (i = 0; i < EXP_INCREMENT_STEPS; i++) \
    {                                         \
        $body;                                \
        n *= EXP_INCREMENT_BASE;              \
    }                                         \
})

#define MEASURE_TIME_TABLE($init, $func,                     \
                           $f1_name, $f2_name, $f3_name,     \
                           $f1, $f2, $f3) ({                 \
    int v[LAST_N];                                           \
    double t;                                                \
    double times[EXP_INCREMENT_STEPS];                       \
                                                             \
    EXPONENTIAL_INCREMENT({                                  \
        ($init)(v, n);                                       \
        t = TIME_IT(($func)(v, n));                          \
                                                             \
        if (t < TRUSTED_TIME)                                \
            t = TIME_REPEATED(($init)(v, n), ($func)(v, n)); \
        times[i] = t;                                        \
    });                                                      \
                                                             \
    print_table(times,                                       \
                $f1_name, $f2_name, $f3_name,                \
                $f1, $f2, $f3);                              \
})

#endif
