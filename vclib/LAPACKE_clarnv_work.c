#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clarnv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clarnv_work)( /* LAPACKE_clarnv_work */
    lapack_int            /* idist */,
    lapack_int *            /* iseed */,
    lapack_int            /* n */,
    lapack_complex_float *            /* x */
);
static PFNLAPACKE_clarnv_work _g_LAPACKE_clarnv_work = NULL;
lapack_int LAPACKE_clarnv_work(
    lapack_int            idist,
    lapack_int *            iseed,
    lapack_int            n,
    lapack_complex_float *            x
)
{
    if(_g_LAPACKE_clarnv_work==NULL) {
        _g_LAPACKE_clarnv_work = rindow_load_libopenblas_func("LAPACKE_clarnv_work"); 
        if(_g_LAPACKE_clarnv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clarnv_work(
        idist,
        iseed,
        n,
        x    
    );
}
