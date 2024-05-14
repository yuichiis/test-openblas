#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlarcm not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlarcm)( /* LAPACKE_zlarcm */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_zlarcm _g_LAPACKE_zlarcm = NULL;
lapack_int LAPACKE_zlarcm(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_zlarcm==NULL) {
        _g_LAPACKE_zlarcm = rindow_load_libopenblas_func("LAPACKE_zlarcm"); 
        if(_g_LAPACKE_zlarcm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlarcm(
        matrix_layout,
        m,
        n,
        a,
        lda,
        b,
        ldb,
        c,
        ldc    
    );
}
