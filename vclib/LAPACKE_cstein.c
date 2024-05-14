#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cstein not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cstein)( /* LAPACKE_cstein */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    const float *            /* d */,
    const float *            /* e */,
    lapack_int            /* m */,
    const float *            /* w */,
    const lapack_int *            /* iblock */,
    const lapack_int *            /* isplit */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifailv */
);
static PFNLAPACKE_cstein _g_LAPACKE_cstein = NULL;
lapack_int LAPACKE_cstein(
    int            matrix_layout,
    lapack_int            n,
    const float *            d,
    const float *            e,
    lapack_int            m,
    const float *            w,
    const lapack_int *            iblock,
    const lapack_int *            isplit,
    lapack_complex_float *            z,
    lapack_int            ldz,
    lapack_int *            ifailv
)
{
    if(_g_LAPACKE_cstein==NULL) {
        _g_LAPACKE_cstein = rindow_load_libopenblas_func("LAPACKE_cstein"); 
        if(_g_LAPACKE_cstein==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cstein(
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
