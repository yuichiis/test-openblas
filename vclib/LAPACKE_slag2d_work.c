#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slag2d_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slag2d_work)( /* LAPACKE_slag2d_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* sa */,
    lapack_int            /* ldsa */,
    double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_slag2d_work _g_LAPACKE_slag2d_work = NULL;
lapack_int LAPACKE_slag2d_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const float *            sa,
    lapack_int            ldsa,
    double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_slag2d_work==NULL) {
        _g_LAPACKE_slag2d_work = rindow_load_libopenblas_func("LAPACKE_slag2d_work"); 
        if(_g_LAPACKE_slag2d_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slag2d_work(
        matrix_layout,
        m,
        n,
        sa,
        ldsa,
        a,
        lda    
    );
}
