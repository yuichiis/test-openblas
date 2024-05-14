#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpptri)( /* LAPACKE_cpptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */
);
static PFNLAPACKE_cpptri _g_LAPACKE_cpptri = NULL;
lapack_int LAPACKE_cpptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap
)
{
    if(_g_LAPACKE_cpptri==NULL) {
        _g_LAPACKE_cpptri = rindow_load_libopenblas_func("LAPACKE_cpptri"); 
        if(_g_LAPACKE_cpptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpptri(
        matrix_layout,
        uplo,
        n,
        ap    
    );
}
