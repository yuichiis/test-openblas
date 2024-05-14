#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zggglm not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zggglm)( /* LAPACKE_zggglm */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* d */,
    lapack_complex_double *            /* x */,
    lapack_complex_double *            /* y */
);
static PFNLAPACKE_zggglm _g_LAPACKE_zggglm = NULL;
lapack_int LAPACKE_zggglm(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            m,
    lapack_int            p,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            d,
    lapack_complex_double *            x,
    lapack_complex_double *            y
)
{
    if(_g_LAPACKE_zggglm==NULL) {
        _g_LAPACKE_zggglm = rindow_load_libopenblas_func("LAPACKE_zggglm"); 
        if(_g_LAPACKE_zggglm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zggglm(
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
