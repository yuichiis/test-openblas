#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssprfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssprfs)( /* LAPACKE_ssprfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* ap */,
    const float *            /* afp */,
    const lapack_int *            /* ipiv */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_ssprfs _g_LAPACKE_ssprfs = NULL;
lapack_int LAPACKE_ssprfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            ap,
    const float *            afp,
    const lapack_int *            ipiv,
    const float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_ssprfs==NULL) {
        _g_LAPACKE_ssprfs = rindow_load_libopenblas_func("LAPACKE_ssprfs"); 
        if(_g_LAPACKE_ssprfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssprfs(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        afp,
        ipiv,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr    
    );
}
