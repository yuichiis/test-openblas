#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggglm not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggglm)( /* LAPACKE_dggglm */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* d */,
    double *            /* x */,
    double *            /* y */
);
static PFNLAPACKE_dggglm _g_LAPACKE_dggglm = NULL;
lapack_int LAPACKE_dggglm(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            m,
    lapack_int            p,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            d,
    double *            x,
    double *            y
)
{
    if(_g_LAPACKE_dggglm==NULL) {
        _g_LAPACKE_dggglm = rindow_load_libopenblas_func("LAPACKE_dggglm"); 
        if(_g_LAPACKE_dggglm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggglm(
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
