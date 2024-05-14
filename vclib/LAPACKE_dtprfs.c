#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtprfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtprfs)( /* LAPACKE_dtprfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* ap */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    const double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_dtprfs _g_LAPACKE_dtprfs = NULL;
lapack_int LAPACKE_dtprfs(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            ap,
    const double *            b,
    lapack_int            ldb,
    const double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_dtprfs==NULL) {
        _g_LAPACKE_dtprfs = rindow_load_libopenblas_func("LAPACKE_dtprfs"); 
        if(_g_LAPACKE_dtprfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtprfs(
        matrix_layout,
        uplo,
        trans,
        diag,
        n,
        nrhs,
        ap,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr    
    );
}
