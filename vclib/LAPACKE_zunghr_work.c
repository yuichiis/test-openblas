#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zunghr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zunghr_work)( /* LAPACKE_zunghr_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_zunghr_work _g_LAPACKE_zunghr_work = NULL;
lapack_int LAPACKE_zunghr_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            tau,
    lapack_complex_double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_zunghr_work==NULL) {
        _g_LAPACKE_zunghr_work = rindow_load_libopenblas_func("LAPACKE_zunghr_work"); 
        if(_g_LAPACKE_zunghr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zunghr_work(
        matrix_layout,
        n,
        ilo,
        ihi,
        a,
        lda,
        tau,
        work,
        lwork    
    );
}
