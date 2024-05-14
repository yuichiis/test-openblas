#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggglm not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggglm)( /* LAPACKE_cggglm */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* d */,
    lapack_complex_float *            /* x */,
    lapack_complex_float *            /* y */
);
static PFNLAPACKE_cggglm _g_LAPACKE_cggglm = NULL;
lapack_int LAPACKE_cggglm(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            m,
    lapack_int            p,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            d,
    lapack_complex_float *            x,
    lapack_complex_float *            y
)
{
    if(_g_LAPACKE_cggglm==NULL) {
        _g_LAPACKE_cggglm = rindow_load_libopenblas_func("LAPACKE_cggglm"); 
        if(_g_LAPACKE_cggglm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggglm(
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
