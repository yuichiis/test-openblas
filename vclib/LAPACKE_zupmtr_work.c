#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zupmtr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zupmtr_work)( /* LAPACKE_zupmtr_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* ap */,
    const lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zupmtr_work _g_LAPACKE_zupmtr_work = NULL;
lapack_int LAPACKE_zupmtr_work(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_double *            ap,
    const lapack_complex_double *            tau,
    lapack_complex_double *            c,
    lapack_int            ldc,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zupmtr_work==NULL) {
        _g_LAPACKE_zupmtr_work = rindow_load_libopenblas_func("LAPACKE_zupmtr_work"); 
        if(_g_LAPACKE_zupmtr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zupmtr_work(
        matrix_layout,
        side,
        uplo,
        trans,
        m,
        n,
        ap,
        tau,
        c,
        ldc,
        work    
    );
}
