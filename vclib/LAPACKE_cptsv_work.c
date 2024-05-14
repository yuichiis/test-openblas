#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cptsv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cptsv_work)( /* LAPACKE_cptsv_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    float *            /* d */,
    lapack_complex_float *            /* e */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cptsv_work _g_LAPACKE_cptsv_work = NULL;
lapack_int LAPACKE_cptsv_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    float *            d,
    lapack_complex_float *            e,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cptsv_work==NULL) {
        _g_LAPACKE_cptsv_work = rindow_load_libopenblas_func("LAPACKE_cptsv_work"); 
        if(_g_LAPACKE_cptsv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cptsv_work(
        matrix_layout,
        n,
        nrhs,
        d,
        e,
        b,
        ldb    
    );
}
