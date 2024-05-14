#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sporfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sporfs)( /* LAPACKE_sporfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* af */,
    lapack_int            /* ldaf */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_sporfs _g_LAPACKE_sporfs = NULL;
lapack_int LAPACKE_sporfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            a,
    lapack_int            lda,
    const float *            af,
    lapack_int            ldaf,
    const float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_sporfs==NULL) {
        _g_LAPACKE_sporfs = rindow_load_libopenblas_func("LAPACKE_sporfs"); 
        if(_g_LAPACKE_sporfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sporfs(
        matrix_layout,
        uplo,
        n,
        nrhs,
        a,
        lda,
        af,
        ldaf,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr    
    );
}
