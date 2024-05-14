#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlasrt_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlasrt_work)( /* LAPACKE_dlasrt_work */
    char            /* id */,
    lapack_int            /* n */,
    double *            /* d */
);
static PFNLAPACKE_dlasrt_work _g_LAPACKE_dlasrt_work = NULL;
lapack_int LAPACKE_dlasrt_work(
    char            id,
    lapack_int            n,
    double *            d
)
{
    if(_g_LAPACKE_dlasrt_work==NULL) {
        _g_LAPACKE_dlasrt_work = rindow_load_libopenblas_func("LAPACKE_dlasrt_work"); 
        if(_g_LAPACKE_dlasrt_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlasrt_work(
        id,
        n,
        d    
    );
}
