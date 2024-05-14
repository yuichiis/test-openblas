#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spbrfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spbrfs)( /* LAPACKE_spbrfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    const float *            /* ab */,
    lapack_int            /* ldab */,
    const float *            /* afb */,
    lapack_int            /* ldafb */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_spbrfs _g_LAPACKE_spbrfs = NULL;
lapack_int LAPACKE_spbrfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    const float *            ab,
    lapack_int            ldab,
    const float *            afb,
    lapack_int            ldafb,
    const float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_spbrfs==NULL) {
        _g_LAPACKE_spbrfs = rindow_load_libopenblas_func("LAPACKE_spbrfs"); 
        if(_g_LAPACKE_spbrfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spbrfs(
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
