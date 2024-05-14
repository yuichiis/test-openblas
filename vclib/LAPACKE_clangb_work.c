#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clangb_work not found\n";
typedef float (CALLBACK* PFNLAPACKE_clangb_work)( /* LAPACKE_clangb_work */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* work */
);
static PFNLAPACKE_clangb_work _g_LAPACKE_clangb_work = NULL;
float LAPACKE_clangb_work(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const lapack_complex_float *            ab,
    lapack_int            ldab,
    float *            work
)
{
    if(_g_LAPACKE_clangb_work==NULL) {
        _g_LAPACKE_clangb_work = rindow_load_libopenblas_func("LAPACKE_clangb_work"); 
        if(_g_LAPACKE_clangb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clangb_work(
        matrix_layout,
        norm,
        n,
        kl,
        ku,
        ab,
        ldab,
        work    
    );
}
