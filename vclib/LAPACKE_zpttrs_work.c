#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpttrs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpttrs_work)( /* LAPACKE_zpttrs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* d */,
    const lapack_complex_double *            /* e */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zpttrs_work _g_LAPACKE_zpttrs_work = NULL;
lapack_int LAPACKE_zpttrs_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            d,
    const lapack_complex_double *            e,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zpttrs_work==NULL) {
        _g_LAPACKE_zpttrs_work = rindow_load_libopenblas_func("LAPACKE_zpttrs_work"); 
        if(_g_LAPACKE_zpttrs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpttrs_work(
        matrix_layout,
        uplo,
        n,
        nrhs,
        d,
        e,
        b,
        ldb    
    );
}
