#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zporfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zporfs)( /* LAPACKE_zporfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* af */,
    lapack_int            /* ldaf */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_zporfs _g_LAPACKE_zporfs = NULL;
lapack_int LAPACKE_zporfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            af,
    lapack_int            ldaf,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_zporfs==NULL) {
        _g_LAPACKE_zporfs = rindow_load_libopenblas_func("LAPACKE_zporfs"); 
        if(_g_LAPACKE_zporfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zporfs(
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
