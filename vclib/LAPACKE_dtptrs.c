#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtptrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtptrs)( /* LAPACKE_dtptrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* ap */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dtptrs _g_LAPACKE_dtptrs = NULL;
lapack_int LAPACKE_dtptrs(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            ap,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dtptrs==NULL) {
        _g_LAPACKE_dtptrs = rindow_load_libopenblas_func("LAPACKE_dtptrs"); 
        if(_g_LAPACKE_dtptrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtptrs(
        matrix_layout,
        uplo,
        trans,
        diag,
        n,
        nrhs,
        ap,
        b,
        ldb    
    );
}
