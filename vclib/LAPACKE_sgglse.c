#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgglse not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgglse)( /* LAPACKE_sgglse */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* p */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* c */,
    float *            /* d */,
    float *            /* x */
);
static PFNLAPACKE_sgglse _g_LAPACKE_sgglse = NULL;
lapack_int LAPACKE_sgglse(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            p,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            c,
    float *            d,
    float *            x
)
{
    if(_g_LAPACKE_sgglse==NULL) {
        _g_LAPACKE_sgglse = rindow_load_libopenblas_func("LAPACKE_sgglse"); 
        if(_g_LAPACKE_sgglse==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgglse(
        matrix_layout,
        m,
        n,
        p,
        a,
        lda,
        b,
        ldb,
        c,
        d,
        x    
    );
}
