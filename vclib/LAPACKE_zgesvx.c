#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgesvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgesvx)( /* LAPACKE_zgesvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* af */,
    lapack_int            /* ldaf */,
    lapack_int *            /* ipiv */,
    char *            /* equed */,
    double *            /* r */,
    double *            /* c */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */,
    double *            /* rpivot */
);
static PFNLAPACKE_zgesvx _g_LAPACKE_zgesvx = NULL;
lapack_int LAPACKE_zgesvx(
    int            matrix_layout,
    char            fact,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            af,
    lapack_int            ldaf,
    lapack_int *            ipiv,
    char *            equed,
    double *            r,
    double *            c,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr,
    double *            rpivot
)
{
    if(_g_LAPACKE_zgesvx==NULL) {
        _g_LAPACKE_zgesvx = rindow_load_libopenblas_func("LAPACKE_zgesvx"); 
        if(_g_LAPACKE_zgesvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgesvx(
        matrix_layout,
        fact,
        trans,
        n,
        nrhs,
        a,
        lda,
        af,
        ldaf,
        ipiv,
        equed,
        r,
        c,
        b,
        ldb,
        x,
        ldx,
        rcond,
        ferr,
        berr,
        rpivot    
    );
}
