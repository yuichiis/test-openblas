#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtpmqrt not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtpmqrt)( /* LAPACKE_dtpmqrt */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* l */,
    lapack_int            /* nb */,
    const double *            /* v */,
    lapack_int            /* ldv */,
    const double *            /* t */,
    lapack_int            /* ldt */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dtpmqrt _g_LAPACKE_dtpmqrt = NULL;
lapack_int LAPACKE_dtpmqrt(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_int            l,
    lapack_int            nb,
    const double *            v,
    lapack_int            ldv,
    const double *            t,
    lapack_int            ldt,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dtpmqrt==NULL) {
        _g_LAPACKE_dtpmqrt = rindow_load_libopenblas_func("LAPACKE_dtpmqrt"); 
        if(_g_LAPACKE_dtpmqrt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtpmqrt(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        l,
        nb,
        v,
        ldv,
        t,
        ldt,
        a,
        lda,
        b,
        ldb    
    );
}
