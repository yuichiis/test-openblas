#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dppsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dppsvx)( /* LAPACKE_dppsvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* ap */,
    double *            /* afp */,
    char *            /* equed */,
    double *            /* s */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_dppsvx _g_LAPACKE_dppsvx = NULL;
lapack_int LAPACKE_dppsvx(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    double *            ap,
    double *            afp,
    char *            equed,
    double *            s,
    double *            b,
    lapack_int            ldb,
    double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_dppsvx==NULL) {
        _g_LAPACKE_dppsvx = rindow_load_libopenblas_func("LAPACKE_dppsvx"); 
        if(_g_LAPACKE_dppsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dppsvx(
        matrix_layout,
        fact,
        uplo,
        n,
        nrhs,
        ap,
        afp,
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
