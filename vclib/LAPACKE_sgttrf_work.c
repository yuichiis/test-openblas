#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgttrf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgttrf_work)( /* LAPACKE_sgttrf_work */
    lapack_int            /* n */,
    float *            /* dl */,
    float *            /* d */,
    float *            /* du */,
    float *            /* du2 */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_sgttrf_work _g_LAPACKE_sgttrf_work = NULL;
lapack_int LAPACKE_sgttrf_work(
    lapack_int            n,
    float *            dl,
    float *            d,
    float *            du,
    float *            du2,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_sgttrf_work==NULL) {
        _g_LAPACKE_sgttrf_work = rindow_load_libopenblas_func("LAPACKE_sgttrf_work"); 
        if(_g_LAPACKE_sgttrf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgttrf_work(
        n,
        dl,
        d,
        du,
        du2,
        ipiv    
    );
}
