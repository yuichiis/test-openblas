#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgemqr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgemqr_work)( /* LAPACKE_cgemqr_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* t */,
    lapack_int            /* tsize */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_cgemqr_work _g_LAPACKE_cgemqr_work = NULL;
lapack_int LAPACKE_cgemqr_work(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            t,
    lapack_int            tsize,
    lapack_complex_float *            c,
    lapack_int            ldc,
    lapack_complex_float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_cgemqr_work==NULL) {
        _g_LAPACKE_cgemqr_work = rindow_load_libopenblas_func("LAPACKE_cgemqr_work"); 
        if(_g_LAPACKE_cgemqr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgemqr_work(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        a,
        lda,
        t,
        tsize,
        c,
        ldc,
        work,
        lwork    
    );
}
