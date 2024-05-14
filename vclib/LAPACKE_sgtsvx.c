#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgtsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgtsvx)( /* LAPACKE_sgtsvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* dl */,
    const float *            /* d */,
    const float *            /* du */,
    float *            /* dlf */,
    float *            /* df */,
    float *            /* duf */,
    float *            /* du2 */,
    lapack_int *            /* ipiv */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_sgtsvx _g_LAPACKE_sgtsvx = NULL;
lapack_int LAPACKE_sgtsvx(
    int            matrix_layout,
    char            fact,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            dl,
    const float *            d,
    const float *            du,
    float *            dlf,
    float *            df,
    float *            duf,
    float *            du2,
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
    if(_g_LAPACKE_sgtsvx==NULL) {
        _g_LAPACKE_sgtsvx = rindow_load_libopenblas_func("LAPACKE_sgtsvx"); 
        if(_g_LAPACKE_sgtsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgtsvx(
        matrix_layout,
        fact,
        trans,
        n,
        nrhs,
        dl,
        d,
        du,
        dlf,
        df,
        duf,
        du2,
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
