#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sppsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sppsvx)( /* LAPACKE_sppsvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    float *            /* ap */,
    float *            /* afp */,
    char *            /* equed */,
    float *            /* s */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_sppsvx _g_LAPACKE_sppsvx = NULL;
lapack_int LAPACKE_sppsvx(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    float *            ap,
    float *            afp,
    char *            equed,
    float *            s,
    float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_sppsvx==NULL) {
        _g_LAPACKE_sppsvx = rindow_load_libopenblas_func("LAPACKE_sppsvx"); 
        if(_g_LAPACKE_sppsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sppsvx(
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
