#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsptri)( /* LAPACKE_dsptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_dsptri _g_LAPACKE_dsptri = NULL;
lapack_int LAPACKE_dsptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            ap,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_dsptri==NULL) {
        _g_LAPACKE_dsptri = rindow_load_libopenblas_func("LAPACKE_dsptri"); 
        if(_g_LAPACKE_dsptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsptri(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}
