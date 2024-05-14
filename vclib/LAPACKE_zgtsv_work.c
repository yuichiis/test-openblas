#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgtsv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgtsv_work)( /* LAPACKE_zgtsv_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* dl */,
    lapack_complex_double *            /* d */,
    lapack_complex_double *            /* du */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zgtsv_work _g_LAPACKE_zgtsv_work = NULL;
lapack_int LAPACKE_zgtsv_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_double *            dl,
    lapack_complex_double *            d,
    lapack_complex_double *            du,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zgtsv_work==NULL) {
        _g_LAPACKE_zgtsv_work = rindow_load_libopenblas_func("LAPACKE_zgtsv_work"); 
        if(_g_LAPACKE_zgtsv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgtsv_work(
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
