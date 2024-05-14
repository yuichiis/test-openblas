#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dopmtr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dopmtr_work)( /* LAPACKE_dopmtr_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* ap */,
    const double *            /* tau */,
    double *            /* c */,
    lapack_int            /* ldc */,
    double *            /* work */
);
static PFNLAPACKE_dopmtr_work _g_LAPACKE_dopmtr_work = NULL;
lapack_int LAPACKE_dopmtr_work(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const double *            ap,
    const double *            tau,
    double *            c,
    lapack_int            ldc,
    double *            work
)
{
    if(_g_LAPACKE_dopmtr_work==NULL) {
        _g_LAPACKE_dopmtr_work = rindow_load_libopenblas_func("LAPACKE_dopmtr_work"); 
        if(_g_LAPACKE_dopmtr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dopmtr_work(
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
