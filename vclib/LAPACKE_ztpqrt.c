#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztpqrt not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztpqrt)( /* LAPACKE_ztpqrt */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* l */,
    lapack_int            /* nb */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_ztpqrt _g_LAPACKE_ztpqrt = NULL;
lapack_int LAPACKE_ztpqrt(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            l,
    lapack_int            nb,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_ztpqrt==NULL) {
        _g_LAPACKE_ztpqrt = rindow_load_libopenblas_func("LAPACKE_ztpqrt"); 
        if(_g_LAPACKE_ztpqrt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztpqrt(
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
