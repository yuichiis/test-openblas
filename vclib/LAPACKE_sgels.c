#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgels not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgels)( /* LAPACKE_sgels */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_sgels _g_LAPACKE_sgels = NULL;
lapack_int LAPACKE_sgels(
    int            matrix_layout,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nrhs,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_sgels==NULL) {
        _g_LAPACKE_sgels = rindow_load_libopenblas_func("LAPACKE_sgels"); 
        if(_g_LAPACKE_sgels==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgels(
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
