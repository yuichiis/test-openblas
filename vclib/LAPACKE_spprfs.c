#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spprfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spprfs)( /* LAPACKE_spprfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* ap */,
    const float *            /* afp */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_spprfs _g_LAPACKE_spprfs = NULL;
lapack_int LAPACKE_spprfs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            ap,
    const float *            afp,
    const float *            b,
    lapack_int            ldb,
    float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_spprfs==NULL) {
        _g_LAPACKE_spprfs = rindow_load_libopenblas_func("LAPACKE_spprfs"); 
        if(_g_LAPACKE_spprfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spprfs(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        afp,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr    
    );
}
