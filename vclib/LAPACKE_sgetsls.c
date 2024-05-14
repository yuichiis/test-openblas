#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgetsls not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgetsls)( /* LAPACKE_sgetsls */
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
static PFNLAPACKE_sgetsls _g_LAPACKE_sgetsls = NULL;
lapack_int LAPACKE_sgetsls(
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
    if(_g_LAPACKE_sgetsls==NULL) {
        _g_LAPACKE_sgetsls = rindow_load_libopenblas_func("LAPACKE_sgetsls"); 
        if(_g_LAPACKE_sgetsls==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgetsls(
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
