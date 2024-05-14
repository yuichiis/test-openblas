#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlassq_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlassq_work)( /* LAPACKE_dlassq_work */
    lapack_int            /* n */,
    double *            /* x */,
    lapack_int            /* incx */,
    double *            /* scale */,
    double *            /* sumsq */
);
static PFNLAPACKE_dlassq_work _g_LAPACKE_dlassq_work = NULL;
lapack_int LAPACKE_dlassq_work(
    lapack_int            n,
    double *            x,
    lapack_int            incx,
    double *            scale,
    double *            sumsq
)
{
    if(_g_LAPACKE_dlassq_work==NULL) {
        _g_LAPACKE_dlassq_work = rindow_load_libopenblas_func("LAPACKE_dlassq_work"); 
        if(_g_LAPACKE_dlassq_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlassq_work(
        n,
        x,
        incx,
        scale,
        sumsq    
    );
}
