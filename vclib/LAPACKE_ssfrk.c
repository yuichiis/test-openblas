#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssfrk not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssfrk)( /* LAPACKE_ssfrk */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    float            /* alpha */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float            /* beta */,
    float *            /* c */
);
static PFNLAPACKE_ssfrk _g_LAPACKE_ssfrk = NULL;
lapack_int LAPACKE_ssfrk(
    int            matrix_layout,
    char            transr,
    char            uplo,
    char            trans,
    lapack_int            n,
    lapack_int            k,
    float            alpha,
    const float *            a,
    lapack_int            lda,
    float            beta,
    float *            c
)
{
    if(_g_LAPACKE_ssfrk==NULL) {
        _g_LAPACKE_ssfrk = rindow_load_libopenblas_func("LAPACKE_ssfrk"); 
        if(_g_LAPACKE_ssfrk==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssfrk(
        matrix_layout,
        transr,
        uplo,
        trans,
        n,
        k,
        alpha,
        a,
        lda,
        beta,
        c    
    );
}
