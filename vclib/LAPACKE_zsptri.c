#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsptri)( /* LAPACKE_zsptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_zsptri _g_LAPACKE_zsptri = NULL;
lapack_int LAPACKE_zsptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_zsptri==NULL) {
        _g_LAPACKE_zsptri = rindow_load_libopenblas_func("LAPACKE_zsptri"); 
        if(_g_LAPACKE_zsptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsptri(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}
