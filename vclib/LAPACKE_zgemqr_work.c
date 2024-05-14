#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgemqr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgemqr_work)( /* LAPACKE_zgemqr_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* t */,
    lapack_int            /* tsize */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_zgemqr_work _g_LAPACKE_zgemqr_work = NULL;
lapack_int LAPACKE_zgemqr_work(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            t,
    lapack_int            tsize,
    lapack_complex_double *            c,
    lapack_int            ldc,
    lapack_complex_double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_zgemqr_work==NULL) {
        _g_LAPACKE_zgemqr_work = rindow_load_libopenblas_func("LAPACKE_zgemqr_work"); 
        if(_g_LAPACKE_zgemqr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgemqr_work(
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
