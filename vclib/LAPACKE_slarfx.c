#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slarfx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slarfx)( /* LAPACKE_slarfx */
    int            /* matrix_layout */,
    char            /* side */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* v */,
    float            /* tau */,
    float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* work */
);
static PFNLAPACKE_slarfx _g_LAPACKE_slarfx = NULL;
lapack_int LAPACKE_slarfx(
    int            matrix_layout,
    char            side,
    lapack_int            m,
    lapack_int            n,
    const float *            v,
    float            tau,
    float *            c,
    lapack_int            ldc,
    float *            work
)
{
    if(_g_LAPACKE_slarfx==NULL) {
        _g_LAPACKE_slarfx = rindow_load_libopenblas_func("LAPACKE_slarfx"); 
        if(_g_LAPACKE_slarfx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slarfx(
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
