#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpttrs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpttrs_work)( /* LAPACKE_dpttrs_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* d */,
    const double *            /* e */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dpttrs_work _g_LAPACKE_dpttrs_work = NULL;
lapack_int LAPACKE_dpttrs_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            d,
    const double *            e,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dpttrs_work==NULL) {
        _g_LAPACKE_dpttrs_work = rindow_load_libopenblas_func("LAPACKE_dpttrs_work"); 
        if(_g_LAPACKE_dpttrs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpttrs_work(
        matrix_layout,
        n,
        nrhs,
        d,
        e,
        b,
        ldb    
    );
}
