#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorgqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorgqr)( /* LAPACKE_sorgqr */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */
);
static PFNLAPACKE_sorgqr _g_LAPACKE_sorgqr = NULL;
lapack_int LAPACKE_sorgqr(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    float *            a,
    lapack_int            lda,
    const float *            tau
)
{
    if(_g_LAPACKE_sorgqr==NULL) {
        _g_LAPACKE_sorgqr = rindow_load_libopenblas_func("LAPACKE_sorgqr"); 
        if(_g_LAPACKE_sorgqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorgqr(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}
