#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlarfx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlarfx)( /* LAPACKE_dlarfx */
    int            /* matrix_layout */,
    char            /* side */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* v */,
    double            /* tau */,
    double *            /* c */,
    lapack_int            /* ldc */,
    double *            /* work */
);
static PFNLAPACKE_dlarfx _g_LAPACKE_dlarfx = NULL;
lapack_int LAPACKE_dlarfx(
    int            matrix_layout,
    char            side,
    lapack_int            m,
    lapack_int            n,
    const double *            v,
    double            tau,
    double *            c,
    lapack_int            ldc,
    double *            work
)
{
    if(_g_LAPACKE_dlarfx==NULL) {
        _g_LAPACKE_dlarfx = rindow_load_libopenblas_func("LAPACKE_dlarfx"); 
        if(_g_LAPACKE_dlarfx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlarfx(
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
