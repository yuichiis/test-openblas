#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sormtr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sormtr_work)( /* LAPACKE_sormtr_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */,
    float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sormtr_work _g_LAPACKE_sormtr_work = NULL;
lapack_int LAPACKE_sormtr_work(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    const float *            tau,
    float *            c,
    lapack_int            ldc,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sormtr_work==NULL) {
        _g_LAPACKE_sormtr_work = rindow_load_libopenblas_func("LAPACKE_sormtr_work"); 
        if(_g_LAPACKE_sormtr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sormtr_work(
        matrix_layout,
        side,
        uplo,
        trans,
        m,
        n,
        a,
        lda,
        tau,
        c,
        ldc,
        work,
        lwork    
    );
}
