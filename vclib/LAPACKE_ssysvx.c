#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssysvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssysvx)( /* LAPACKE_ssysvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* af */,
    lapack_int            /* ldaf */,
    lapack_int *            /* ipiv */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_ssysvx _g_LAPACKE_ssysvx = NULL;
lapack_int LAPACKE_ssysvx(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            a,
    lapack_int            lda,
    float *            af,
    lapack_int            ldaf,
    lapack_int *            ipiv,
    const float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_ssysvx==NULL) {
        _g_LAPACKE_ssysvx = rindow_load_libopenblas_func("LAPACKE_ssysvx"); 
        if(_g_LAPACKE_ssysvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssysvx(
        matrix_layout,
        fact,
        uplo,
        n,
        nrhs,
        a,
        lda,
        af,
        ldaf,
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
