#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggglm not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggglm)( /* LAPACKE_sggglm */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* d */,
    float *            /* x */,
    float *            /* y */
);
static PFNLAPACKE_sggglm _g_LAPACKE_sggglm = NULL;
lapack_int LAPACKE_sggglm(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            m,
    lapack_int            p,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            d,
    float *            x,
    float *            y
)
{
    if(_g_LAPACKE_sggglm==NULL) {
        _g_LAPACKE_sggglm = rindow_load_libopenblas_func("LAPACKE_sggglm"); 
        if(_g_LAPACKE_sggglm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggglm(
        matrix_layout,
        n,
        m,
        p,
        a,
        lda,
        b,
        ldb,
        d,
        x,
        y    
    );
}
