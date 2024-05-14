#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgemqrt not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgemqrt)( /* LAPACKE_dgemqrt */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* nb */,
    const double *            /* v */,
    lapack_int            /* ldv */,
    const double *            /* t */,
    lapack_int            /* ldt */,
    double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_dgemqrt _g_LAPACKE_dgemqrt = NULL;
lapack_int LAPACKE_dgemqrt(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_int            nb,
    const double *            v,
    lapack_int            ldv,
    const double *            t,
    lapack_int            ldt,
    double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_dgemqrt==NULL) {
        _g_LAPACKE_dgemqrt = rindow_load_libopenblas_func("LAPACKE_dgemqrt"); 
        if(_g_LAPACKE_dgemqrt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgemqrt(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        nb,
        v,
        ldv,
        t,
        ldt,
        c,
        ldc    
    );
}
