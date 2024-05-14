#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhpsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhpsvx)( /* LAPACKE_zhpsvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* ap */,
    lapack_complex_double *            /* afp */,
    lapack_int *            /* ipiv */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* rcond */,
    double *            /* ferr */,
    double *            /* berr */
);
static PFNLAPACKE_zhpsvx _g_LAPACKE_zhpsvx = NULL;
lapack_int LAPACKE_zhpsvx(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_double *            ap,
    lapack_complex_double *            afp,
    lapack_int *            ipiv,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    double *            rcond,
    double *            ferr,
    double *            berr
)
{
    if(_g_LAPACKE_zhpsvx==NULL) {
        _g_LAPACKE_zhpsvx = rindow_load_libopenblas_func("LAPACKE_zhpsvx"); 
        if(_g_LAPACKE_zhpsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhpsvx(
        matrix_layout,
        fact,
        uplo,
        n,
        nrhs,
        ap,
        afp,
        ipiv,
        b,
        ldb,
        x,
        ldx,
        rcond,
        ferr,
        berr    
    );
}
