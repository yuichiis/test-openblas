#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtptri)( /* LAPACKE_dtptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    double *            /* ap */
);
static PFNLAPACKE_dtptri _g_LAPACKE_dtptri = NULL;
lapack_int LAPACKE_dtptri(
    int            matrix_layout,
    char            uplo,
    char            diag,
    lapack_int            n,
    double *            ap
)
{
    if(_g_LAPACKE_dtptri==NULL) {
        _g_LAPACKE_dtptri = rindow_load_libopenblas_func("LAPACKE_dtptri"); 
        if(_g_LAPACKE_dtptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtptri(
        matrix_layout,
        uplo,
        diag,
        n,
        ap    
    );
}
