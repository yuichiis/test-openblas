#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zstein not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zstein)( /* LAPACKE_zstein */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    const double *            /* d */,
    const double *            /* e */,
    lapack_int            /* m */,
    const double *            /* w */,
    const lapack_int *            /* iblock */,
    const lapack_int *            /* isplit */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifailv */
);
static PFNLAPACKE_zstein _g_LAPACKE_zstein = NULL;
lapack_int LAPACKE_zstein(
    int            matrix_layout,
    lapack_int            n,
    const double *            d,
    const double *            e,
    lapack_int            m,
    const double *            w,
    const lapack_int *            iblock,
    const lapack_int *            isplit,
    lapack_complex_double *            z,
    lapack_int            ldz,
    lapack_int *            ifailv
)
{
    if(_g_LAPACKE_zstein==NULL) {
        _g_LAPACKE_zstein = rindow_load_libopenblas_func("LAPACKE_zstein"); 
        if(_g_LAPACKE_zstein==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zstein(
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
