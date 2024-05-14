#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csptri)( /* LAPACKE_csptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_csptri _g_LAPACKE_csptri = NULL;
lapack_int LAPACKE_csptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_csptri==NULL) {
        _g_LAPACKE_csptri = rindow_load_libopenblas_func("LAPACKE_csptri"); 
        if(_g_LAPACKE_csptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csptri(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}
