#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sormrz_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sormrz_work)( /* LAPACKE_sormrz_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* l */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */,
    float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sormrz_work _g_LAPACKE_sormrz_work = NULL;
lapack_int LAPACKE_sormrz_work(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_int            l,
    const float *            a,
    lapack_int            lda,
    const float *            tau,
    float *            c,
    lapack_int            ldc,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sormrz_work==NULL) {
        _g_LAPACKE_sormrz_work = rindow_load_libopenblas_func("LAPACKE_sormrz_work"); 
        if(_g_LAPACKE_sormrz_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sormrz_work(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        l,
        a,
        lda,
        tau,
        c,
        ldc,
        work,
        lwork    
    );
}
