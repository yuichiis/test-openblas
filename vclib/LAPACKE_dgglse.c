#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgglse not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgglse)( /* LAPACKE_dgglse */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* p */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* c */,
    double *            /* d */,
    double *            /* x */
);
static PFNLAPACKE_dgglse _g_LAPACKE_dgglse = NULL;
lapack_int LAPACKE_dgglse(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            p,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            c,
    double *            d,
    double *            x
)
{
    if(_g_LAPACKE_dgglse==NULL) {
        _g_LAPACKE_dgglse = rindow_load_libopenblas_func("LAPACKE_dgglse"); 
        if(_g_LAPACKE_dgglse==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgglse(
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
