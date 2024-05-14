#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dstein not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dstein)( /* LAPACKE_dstein */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    const double *            /* d */,
    const double *            /* e */,
    lapack_int            /* m */,
    const double *            /* w */,
    const lapack_int *            /* iblock */,
    const lapack_int *            /* isplit */,
    double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifailv */
);
static PFNLAPACKE_dstein _g_LAPACKE_dstein = NULL;
lapack_int LAPACKE_dstein(
    int            matrix_layout,
    lapack_int            n,
    const double *            d,
    const double *            e,
    lapack_int            m,
    const double *            w,
    const lapack_int *            iblock,
    const lapack_int *            isplit,
    double *            z,
    lapack_int            ldz,
    lapack_int *            ifailv
)
{
    if(_g_LAPACKE_dstein==NULL) {
        _g_LAPACKE_dstein = rindow_load_libopenblas_func("LAPACKE_dstein"); 
        if(_g_LAPACKE_dstein==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dstein(
        matrix_layout,
        n,
        d,
        e,
        m,
        w,
        iblock,
        isplit,
        z,
        ldz,
        ifailv    
    );
}
