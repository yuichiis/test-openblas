#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgels not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgels)( /* LAPACKE_dgels */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dgels _g_LAPACKE_dgels = NULL;
lapack_int LAPACKE_dgels(
    int            matrix_layout,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nrhs,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dgels==NULL) {
        _g_LAPACKE_dgels = rindow_load_libopenblas_func("LAPACKE_dgels"); 
        if(_g_LAPACKE_dgels==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgels(
        matrix_layout,
        trans,
        m,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb    
    );
}
