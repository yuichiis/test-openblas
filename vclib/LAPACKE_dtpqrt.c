#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtpqrt not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtpqrt)( /* LAPACKE_dtpqrt */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* l */,
    lapack_int            /* nb */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_dtpqrt _g_LAPACKE_dtpqrt = NULL;
lapack_int LAPACKE_dtpqrt(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            l,
    lapack_int            nb,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_dtpqrt==NULL) {
        _g_LAPACKE_dtpqrt = rindow_load_libopenblas_func("LAPACKE_dtpqrt"); 
        if(_g_LAPACKE_dtpqrt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtpqrt(
        matrix_layout,
        m,
        n,
        l,
        nb,
        a,
        lda,
        b,
        ldb,
        t,
        ldt    
    );
}
