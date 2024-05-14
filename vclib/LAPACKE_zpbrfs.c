#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpbrfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpbrfs)( /* LAPACKE_zpbrfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_complex_double *            /* afb */,
    lapack_int            /* ldafb */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_zpbrfs _g_LAPACKE_zpbrfs = NULL;
lapack_int LAPACKE_zpbrfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    const lapack_complex_double *            ab,
    lapack_int            ldab,
    const lapack_complex_double *            afb,
    lapack_int            ldafb,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_zpbrfs==NULL) {
        _g_LAPACKE_zpbrfs = rindow_load_libopenblas_func("LAPACKE_zpbrfs"); 
        if(_g_LAPACKE_zpbrfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpbrfs(
        matrix_layout,
        uplo,
        n,
        kd,
        nrhs,
        ab,
        ldab,
        afb,
        ldafb,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr    
    );
}
