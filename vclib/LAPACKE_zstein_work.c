#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zstein_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zstein_work)( /* LAPACKE_zstein_work */
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
    double *            /* work */,
    lapack_int *            /* iwork */,
    lapack_int *            /* ifailv */
);
static PFNLAPACKE_zstein_work _g_LAPACKE_zstein_work = NULL;
lapack_int LAPACKE_zstein_work(
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
    double *            work,
    lapack_int *            iwork,
    lapack_int *            ifailv
)
{
    if(_g_LAPACKE_zstein_work==NULL) {
        _g_LAPACKE_zstein_work = rindow_load_libopenblas_func("LAPACKE_zstein_work"); 
        if(_g_LAPACKE_zstein_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zstein_work(
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
        work,
        iwork,
        ifailv    
    );
}
