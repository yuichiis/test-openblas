#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_classq_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_classq_work)( /* LAPACKE_classq_work */
    lapack_int            /* n */,
    lapack_complex_float *            /* x */,
    lapack_int            /* incx */,
    float *            /* scale */,
    float *            /* sumsq */
);
static PFNLAPACKE_classq_work _g_LAPACKE_classq_work = NULL;
lapack_int LAPACKE_classq_work(
    lapack_int            n,
    lapack_complex_float *            x,
    lapack_int            incx,
    float *            scale,
    float *            sumsq
)
{
    if(_g_LAPACKE_classq_work==NULL) {
        _g_LAPACKE_classq_work = rindow_load_libopenblas_func("LAPACKE_classq_work"); 
        if(_g_LAPACKE_classq_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_classq_work(
        n,
        x,
        incx,
        scale,
        sumsq    
    );
}
