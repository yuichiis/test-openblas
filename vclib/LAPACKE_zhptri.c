#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhptri)( /* LAPACKE_zhptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_zhptri _g_LAPACKE_zhptri = NULL;
lapack_int LAPACKE_zhptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_zhptri==NULL) {
        _g_LAPACKE_zhptri = rindow_load_libopenblas_func("LAPACKE_zhptri"); 
        if(_g_LAPACKE_zhptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhptri(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}
