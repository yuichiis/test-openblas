#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpprfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpprfs)( /* LAPACKE_zpprfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* ap */,
    const lapack_complex_double *            /* afp */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_zpprfs _g_LAPACKE_zpprfs = NULL;
lapack_int LAPACKE_zpprfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_double *            ap,
    const lapack_complex_double *            afp,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_zpprfs==NULL) {
        _g_LAPACKE_zpprfs = rindow_load_libopenblas_func("LAPACKE_zpprfs"); 
        if(_g_LAPACKE_zpprfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpprfs(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        afp,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr    
    );
}
