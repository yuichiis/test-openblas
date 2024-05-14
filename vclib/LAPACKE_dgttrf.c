#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgttrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgttrf)( /* LAPACKE_dgttrf */
    lapack_int            /* n */,
    double *            /* dl */,
    double *            /* d */,
    double *            /* du */,
    double *            /* du2 */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_dgttrf _g_LAPACKE_dgttrf = NULL;
lapack_int LAPACKE_dgttrf(
    lapack_int            n,
    double *            dl,
    double *            d,
    double *            du,
    double *            du2,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_dgttrf==NULL) {
        _g_LAPACKE_dgttrf = rindow_load_libopenblas_func("LAPACKE_dgttrf"); 
        if(_g_LAPACKE_dgttrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgttrf(
        n,
        dl,
        d,
        du,
        du2,
        ipiv    
    );
}
