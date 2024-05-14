#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgttrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgttrf)( /* LAPACKE_cgttrf */
    lapack_int            /* n */,
    lapack_complex_float *            /* dl */,
    lapack_complex_float *            /* d */,
    lapack_complex_float *            /* du */,
    lapack_complex_float *            /* du2 */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_cgttrf _g_LAPACKE_cgttrf = NULL;
lapack_int LAPACKE_cgttrf(
    lapack_int            n,
    lapack_complex_float *            dl,
    lapack_complex_float *            d,
    lapack_complex_float *            du,
    lapack_complex_float *            du2,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_cgttrf==NULL) {
        _g_LAPACKE_cgttrf = rindow_load_libopenblas_func("LAPACKE_cgttrf"); 
        if(_g_LAPACKE_cgttrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgttrf(
        n,
        dl,
        d,
        du,
        du2,
        ipiv    
    );
}
