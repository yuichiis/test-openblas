#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgglse not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgglse)( /* LAPACKE_zgglse */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* p */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* c */,
    lapack_complex_double *            /* d */,
    lapack_complex_double *            /* x */
);
static PFNLAPACKE_zgglse _g_LAPACKE_zgglse = NULL;
lapack_int LAPACKE_zgglse(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            p,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            c,
    lapack_complex_double *            d,
    lapack_complex_double *            x
)
{
    if(_g_LAPACKE_zgglse==NULL) {
        _g_LAPACKE_zgglse = rindow_load_libopenblas_func("LAPACKE_zgglse"); 
        if(_g_LAPACKE_zgglse==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgglse(
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
