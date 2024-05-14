#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chptri)( /* LAPACKE_chptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_chptri _g_LAPACKE_chptri = NULL;
lapack_int LAPACKE_chptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_chptri==NULL) {
        _g_LAPACKE_chptri = rindow_load_libopenblas_func("LAPACKE_chptri"); 
        if(_g_LAPACKE_chptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chptri(
        matrix_layout,
        uplo,
        n,
        ap,
        ipiv    
    );
}
