#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlarfx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlarfx_work)( /* LAPACKE_zlarfx_work */
    int            /* matrix_layout */,
    char            /* side */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* v */,
    lapack_complex_double            /* tau */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zlarfx_work _g_LAPACKE_zlarfx_work = NULL;
lapack_int LAPACKE_zlarfx_work(
    int            matrix_layout,
    char            side,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_double *            v,
    lapack_complex_double            tau,
    lapack_complex_double *            c,
    lapack_int            ldc,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zlarfx_work==NULL) {
        _g_LAPACKE_zlarfx_work = rindow_load_libopenblas_func("LAPACKE_zlarfx_work"); 
        if(_g_LAPACKE_zlarfx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlarfx_work(
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
