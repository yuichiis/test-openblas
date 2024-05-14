#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zptsv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zptsv_work)( /* LAPACKE_zptsv_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* d */,
    lapack_complex_double *            /* e */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zptsv_work _g_LAPACKE_zptsv_work = NULL;
lapack_int LAPACKE_zptsv_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    double *            d,
    lapack_complex_double *            e,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zptsv_work==NULL) {
        _g_LAPACKE_zptsv_work = rindow_load_libopenblas_func("LAPACKE_zptsv_work"); 
        if(_g_LAPACKE_zptsv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zptsv_work(
        matrix_layout,
        n,
        nrhs,
        d,
        e,
        b,
        ldb    
    );
}
