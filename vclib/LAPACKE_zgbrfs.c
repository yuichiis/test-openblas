#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgbrfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgbrfs)( /* LAPACKE_zgbrfs */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_complex_double *            /* afb */,
    lapack_int            /* ldafb */,
    const lapack_int *            /* ipiv */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_zgbrfs _g_LAPACKE_zgbrfs = NULL;
lapack_int LAPACKE_zgbrfs(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    const lapack_complex_double *            ab,
    lapack_int            ldab,
    const lapack_complex_double *            afb,
    lapack_int            ldafb,
    const lapack_int *            ipiv,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_zgbrfs==NULL) {
        _g_LAPACKE_zgbrfs = rindow_load_libopenblas_func("LAPACKE_zgbrfs"); 
        if(_g_LAPACKE_zgbrfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgbrfs(
        matrix_layout,
        trans,
        n,
        kl,
        ku,
        nrhs,
        ab,
        ldab,
        afb,
        ldafb,
        ipiv,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr    
    );
}
