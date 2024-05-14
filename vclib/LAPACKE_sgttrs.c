#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgttrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgttrs)( /* LAPACKE_sgttrs */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* dl */,
    const float *            /* d */,
    const float *            /* du */,
    const float *            /* du2 */,
    const lapack_int *            /* ipiv */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_sgttrs _g_LAPACKE_sgttrs = NULL;
lapack_int LAPACKE_sgttrs(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            dl,
    const float *            d,
    const float *            du,
    const float *            du2,
    const lapack_int *            ipiv,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_sgttrs==NULL) {
        _g_LAPACKE_sgttrs = rindow_load_libopenblas_func("LAPACKE_sgttrs"); 
        if(_g_LAPACKE_sgttrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgttrs(
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
