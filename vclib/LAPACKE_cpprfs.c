#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpprfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpprfs)( /* LAPACKE_cpprfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* ap */,
    const lapack_complex_float *            /* afp */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_cpprfs _g_LAPACKE_cpprfs = NULL;
lapack_int LAPACKE_cpprfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            ap,
    const lapack_complex_float *            afp,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_cpprfs==NULL) {
        _g_LAPACKE_cpprfs = rindow_load_libopenblas_func("LAPACKE_cpprfs"); 
        if(_g_LAPACKE_cpprfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpprfs(
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
