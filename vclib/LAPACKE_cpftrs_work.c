#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpftrs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpftrs_work)( /* LAPACKE_cpftrs_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* a */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cpftrs_work _g_LAPACKE_cpftrs_work = NULL;
lapack_int LAPACKE_cpftrs_work(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            a,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cpftrs_work==NULL) {
        _g_LAPACKE_cpftrs_work = rindow_load_libopenblas_func("LAPACKE_cpftrs_work"); 
        if(_g_LAPACKE_cpftrs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpftrs_work(
        matrix_layout,
        transr,
        uplo,
        n,
        nrhs,
        a,
        b,
        ldb    
    );
}
