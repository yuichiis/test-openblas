#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssfrk_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssfrk_work)( /* LAPACKE_ssfrk_work */
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
static PFNLAPACKE_ssfrk_work _g_LAPACKE_ssfrk_work = NULL;
lapack_int LAPACKE_ssfrk_work(
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
    if(_g_LAPACKE_ssfrk_work==NULL) {
        _g_LAPACKE_ssfrk_work = rindow_load_libopenblas_func("LAPACKE_ssfrk_work"); 
        if(_g_LAPACKE_ssfrk_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssfrk_work(
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
