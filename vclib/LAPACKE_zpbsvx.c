#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpbsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpbsvx)( /* LAPACKE_zpbsvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    lapack_complex_double *            /* afb */,
    lapack_int            /* ldafb */,
    char *            /* equed */,
    double *            /* s */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_zpbsvx _g_LAPACKE_zpbsvx = NULL;
lapack_int LAPACKE_zpbsvx(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    lapack_complex_double *            ab,
    lapack_int            ldab,
    lapack_complex_double *            afb,
    lapack_int            ldafb,
    char *            equed,
    double *            s,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_zpbsvx==NULL) {
        _g_LAPACKE_zpbsvx = rindow_load_libopenblas_func("LAPACKE_zpbsvx"); 
        if(_g_LAPACKE_zpbsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpbsvx(
        matrix_layout,
        fact,
        uplo,
        n,
        kd,
        nrhs,
        ab,
        ldab,
        afb,
        ldafb,
        equed,
        s,
        b,
        ldb,
        x,
        ldx,
        rcond,
        ferr,
        berr    
    );
}
