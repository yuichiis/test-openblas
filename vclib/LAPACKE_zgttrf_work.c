#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgttrf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgttrf_work)( /* LAPACKE_zgttrf_work */
    lapack_int            /* n */,
    lapack_complex_double *            /* dl */,
    lapack_complex_double *            /* d */,
    lapack_complex_double *            /* du */,
    lapack_complex_double *            /* du2 */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_zgttrf_work _g_LAPACKE_zgttrf_work = NULL;
lapack_int LAPACKE_zgttrf_work(
    lapack_int            n,
    lapack_complex_double *            dl,
    lapack_complex_double *            d,
    lapack_complex_double *            du,
    lapack_complex_double *            du2,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_zgttrf_work==NULL) {
        _g_LAPACKE_zgttrf_work = rindow_load_libopenblas_func("LAPACKE_zgttrf_work"); 
        if(_g_LAPACKE_zgttrf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgttrf_work(
        n,
        dl,
        d,
        du,
        du2,
        ipiv    
    );
}
