#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsfrk not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsfrk)( /* LAPACKE_dsfrk */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    double            /* alpha */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double            /* beta */,
    double *            /* c */
);
static PFNLAPACKE_dsfrk _g_LAPACKE_dsfrk = NULL;
lapack_int LAPACKE_dsfrk(
    int            matrix_layout,
    char            transr,
    char            uplo,
    char            trans,
    lapack_int            n,
    lapack_int            k,
    double            alpha,
    const double *            a,
    lapack_int            lda,
    double            beta,
    double *            c
)
{
    if(_g_LAPACKE_dsfrk==NULL) {
        _g_LAPACKE_dsfrk = rindow_load_libopenblas_func("LAPACKE_dsfrk"); 
        if(_g_LAPACKE_dsfrk==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsfrk(
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
