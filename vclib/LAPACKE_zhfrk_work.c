#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhfrk_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhfrk_work)( /* LAPACKE_zhfrk_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    double            /* alpha */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double            /* beta */,
    lapack_complex_double *            /* c */
);
static PFNLAPACKE_zhfrk_work _g_LAPACKE_zhfrk_work = NULL;
lapack_int LAPACKE_zhfrk_work(
    int            matrix_layout,
    char            transr,
    char            uplo,
    char            trans,
    lapack_int            n,
    lapack_int            k,
    double            alpha,
    const lapack_complex_double *            a,
    lapack_int            lda,
    double            beta,
    lapack_complex_double *            c
)
{
    if(_g_LAPACKE_zhfrk_work==NULL) {
        _g_LAPACKE_zhfrk_work = rindow_load_libopenblas_func("LAPACKE_zhfrk_work"); 
        if(_g_LAPACKE_zhfrk_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhfrk_work(
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
