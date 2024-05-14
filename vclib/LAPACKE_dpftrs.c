#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpftrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpftrs)( /* LAPACKE_dpftrs */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* a */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dpftrs _g_LAPACKE_dpftrs = NULL;
lapack_int LAPACKE_dpftrs(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            a,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dpftrs==NULL) {
        _g_LAPACKE_dpftrs = rindow_load_libopenblas_func("LAPACKE_dpftrs"); 
        if(_g_LAPACKE_dpftrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpftrs(
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
