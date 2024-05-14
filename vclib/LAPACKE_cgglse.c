#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgglse not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgglse)( /* LAPACKE_cgglse */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* p */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* c */,
    lapack_complex_float *            /* d */,
    lapack_complex_float *            /* x */
);
static PFNLAPACKE_cgglse _g_LAPACKE_cgglse = NULL;
lapack_int LAPACKE_cgglse(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            p,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            c,
    lapack_complex_float *            d,
    lapack_complex_float *            x
)
{
    if(_g_LAPACKE_cgglse==NULL) {
        _g_LAPACKE_cgglse = rindow_load_libopenblas_func("LAPACKE_cgglse"); 
        if(_g_LAPACKE_cgglse==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgglse(
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
