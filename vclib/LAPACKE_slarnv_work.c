#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slarnv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slarnv_work)( /* LAPACKE_slarnv_work */
    lapack_int            /* idist */,
    lapack_int *            /* iseed */,
    lapack_int            /* n */,
    float *            /* x */
);
static PFNLAPACKE_slarnv_work _g_LAPACKE_slarnv_work = NULL;
lapack_int LAPACKE_slarnv_work(
    lapack_int            idist,
    lapack_int *            iseed,
    lapack_int            n,
    float *            x
)
{
    if(_g_LAPACKE_slarnv_work==NULL) {
        _g_LAPACKE_slarnv_work = rindow_load_libopenblas_func("LAPACKE_slarnv_work"); 
        if(_g_LAPACKE_slarnv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slarnv_work(
        idist,
        iseed,
        n,
        x    
    );
}
