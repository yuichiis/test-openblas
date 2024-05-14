#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpptri)( /* LAPACKE_zpptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */
);
static PFNLAPACKE_zpptri _g_LAPACKE_zpptri = NULL;
lapack_int LAPACKE_zpptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap
)
{
    if(_g_LAPACKE_zpptri==NULL) {
        _g_LAPACKE_zpptri = rindow_load_libopenblas_func("LAPACKE_zpptri"); 
        if(_g_LAPACKE_zpptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpptri(
        matrix_layout,
        uplo,
        n,
        ap    
    );
}
