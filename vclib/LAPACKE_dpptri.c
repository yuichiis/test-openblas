#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpptri)( /* LAPACKE_dpptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */
);
static PFNLAPACKE_dpptri _g_LAPACKE_dpptri = NULL;
lapack_int LAPACKE_dpptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            ap
)
{
    if(_g_LAPACKE_dpptri==NULL) {
        _g_LAPACKE_dpptri = rindow_load_libopenblas_func("LAPACKE_dpptri"); 
        if(_g_LAPACKE_dpptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpptri(
        matrix_layout,
        uplo,
        n,
        ap    
    );
}
