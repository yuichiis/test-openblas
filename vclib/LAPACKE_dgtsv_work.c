#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgtsv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgtsv_work)( /* LAPACKE_dgtsv_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* dl */,
    double *            /* d */,
    double *            /* du */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dgtsv_work _g_LAPACKE_dgtsv_work = NULL;
lapack_int LAPACKE_dgtsv_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    double *            dl,
    double *            d,
    double *            du,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dgtsv_work==NULL) {
        _g_LAPACKE_dgtsv_work = rindow_load_libopenblas_func("LAPACKE_dgtsv_work"); 
        if(_g_LAPACKE_dgtsv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgtsv_work(
        matrix_layout,
        n,
        nrhs,
        dl,
        d,
        du,
        b,
        ldb    
    );
}
