#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssptri)( /* LAPACKE_ssptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_ssptri _g_LAPACKE_ssptri = NULL;
lapack_int LAPACKE_ssptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            ap,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_ssptri==NULL) {
        _g_LAPACKE_ssptri = rindow_load_libopenblas_func("LAPACKE_ssptri"); 
        if(_g_LAPACKE_ssptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssptri(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}
