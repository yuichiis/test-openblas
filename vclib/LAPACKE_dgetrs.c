#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgetrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgetrs)( /* LAPACKE_dgetrs */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dgetrs _g_LAPACKE_dgetrs = NULL;
lapack_int LAPACKE_dgetrs(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dgetrs==NULL) {
        _g_LAPACKE_dgetrs = rindow_load_libopenblas_func("LAPACKE_dgetrs"); 
        if(_g_LAPACKE_dgetrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgetrs(
        matrix_layout,
        trans,
        n,
        nrhs,
        a,
        lda,
        ipiv,
        b,
        ldb    
    );
}
