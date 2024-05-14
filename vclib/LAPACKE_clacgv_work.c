#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clacgv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clacgv_work)( /* LAPACKE_clacgv_work */
    lapack_int            /* n */,
    lapack_complex_float *            /* x */,
    lapack_int            /* incx */
);
static PFNLAPACKE_clacgv_work _g_LAPACKE_clacgv_work = NULL;
lapack_int LAPACKE_clacgv_work(
    lapack_int            n,
    lapack_complex_float *            x,
    lapack_int            incx
)
{
    if(_g_LAPACKE_clacgv_work==NULL) {
        _g_LAPACKE_clacgv_work = rindow_load_libopenblas_func("LAPACKE_clacgv_work"); 
        if(_g_LAPACKE_clacgv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clacgv_work(
        n,
        x,
        incx    
    );
}
