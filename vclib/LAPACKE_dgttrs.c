#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgttrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgttrs)( /* LAPACKE_dgttrs */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* dl */,
    const double *            /* d */,
    const double *            /* du */,
    const double *            /* du2 */,
    const lapack_int *            /* ipiv */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dgttrs _g_LAPACKE_dgttrs = NULL;
lapack_int LAPACKE_dgttrs(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            dl,
    const double *            d,
    const double *            du,
    const double *            du2,
    const lapack_int *            ipiv,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dgttrs==NULL) {
        _g_LAPACKE_dgttrs = rindow_load_libopenblas_func("LAPACKE_dgttrs"); 
        if(_g_LAPACKE_dgttrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgttrs(
        matrix_layout,
        trans,
        n,
        nrhs,
        dl,
        d,
        du,
        du2,
        ipiv,
        b,
        ldb    
    );
}
