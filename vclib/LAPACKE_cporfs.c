#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cporfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cporfs)( /* LAPACKE_cporfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* af */,
    lapack_int            /* ldaf */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_cporfs _g_LAPACKE_cporfs = NULL;
lapack_int LAPACKE_cporfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            af,
    lapack_int            ldaf,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_cporfs==NULL) {
        _g_LAPACKE_cporfs = rindow_load_libopenblas_func("LAPACKE_cporfs"); 
        if(_g_LAPACKE_cporfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cporfs(
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
