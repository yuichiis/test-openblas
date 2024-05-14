#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgbsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgbsvx)( /* LAPACKE_dgbsvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* afb */,
    lapack_int            /* ldafb */,
    lapack_int *            /* ipiv */,
    char *            /* equed */,
    double *            /* r */,
    double *            /* c */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */,
    double *            /* rpivot */
);
static PFNLAPACKE_dgbsvx _g_LAPACKE_dgbsvx = NULL;
lapack_int LAPACKE_dgbsvx(
    int            matrix_layout,
    char            fact,
    char            trans,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    double *            ab,
    lapack_int            ldab,
    double *            afb,
    lapack_int            ldafb,
    lapack_int *            ipiv,
    char *            equed,
    double *            r,
    double *            c,
    double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr,
    double *            rpivot
)
{
    if(_g_LAPACKE_dgbsvx==NULL) {
        _g_LAPACKE_dgbsvx = rindow_load_libopenblas_func("LAPACKE_dgbsvx"); 
        if(_g_LAPACKE_dgbsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgbsvx(
        matrix_layout,
        fact,
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
