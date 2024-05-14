#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clarfx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clarfx)( /* LAPACKE_clarfx */
    int            /* matrix_layout */,
    char            /* side */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* v */,
    lapack_complex_float            /* tau */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */,
    lapack_complex_float *            /* work */
);
static PFNLAPACKE_clarfx _g_LAPACKE_clarfx = NULL;
lapack_int LAPACKE_clarfx(
    int            matrix_layout,
    char            side,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            v,
    lapack_complex_float            tau,
    lapack_complex_float *            c,
    lapack_int            ldc,
    lapack_complex_float *            work
)
{
    if(_g_LAPACKE_clarfx==NULL) {
        _g_LAPACKE_clarfx = rindow_load_libopenblas_func("LAPACKE_clarfx"); 
        if(_g_LAPACKE_clarfx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clarfx(
        matrix_layout,
        side,
        m,
        n,
        v,
        tau,
        c,
        ldc,
        work    
    );
}
