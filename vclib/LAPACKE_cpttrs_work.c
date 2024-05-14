#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpttrs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpttrs_work)( /* LAPACKE_cpttrs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* d */,
    const lapack_complex_float *            /* e */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cpttrs_work _g_LAPACKE_cpttrs_work = NULL;
lapack_int LAPACKE_cpttrs_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            d,
    const lapack_complex_float *            e,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cpttrs_work==NULL) {
        _g_LAPACKE_cpttrs_work = rindow_load_libopenblas_func("LAPACKE_cpttrs_work"); 
        if(_g_LAPACKE_cpttrs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpttrs_work(
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
