#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slangb_work not found\n";
typedef float (CALLBACK* PFNLAPACKE_slangb_work)( /* LAPACKE_slangb_work */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* work */
);
static PFNLAPACKE_slangb_work _g_LAPACKE_slangb_work = NULL;
float LAPACKE_slangb_work(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const float *            ab,
    lapack_int            ldab,
    float *            work
)
{
    if(_g_LAPACKE_slangb_work==NULL) {
        _g_LAPACKE_slangb_work = rindow_load_libopenblas_func("LAPACKE_slangb_work"); 
        if(_g_LAPACKE_slangb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slangb_work(
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
