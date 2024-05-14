#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgttrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgttrs)( /* LAPACKE_cgttrs */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* dl */,
    const lapack_complex_float *            /* d */,
    const lapack_complex_float *            /* du */,
    const lapack_complex_float *            /* du2 */,
    const lapack_int *            /* ipiv */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cgttrs _g_LAPACKE_cgttrs = NULL;
lapack_int LAPACKE_cgttrs(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            dl,
    const lapack_complex_float *            d,
    const lapack_complex_float *            du,
    const lapack_complex_float *            du2,
    const lapack_int *            ipiv,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cgttrs==NULL) {
        _g_LAPACKE_cgttrs = rindow_load_libopenblas_func("LAPACKE_cgttrs"); 
        if(_g_LAPACKE_cgttrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgttrs(
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
