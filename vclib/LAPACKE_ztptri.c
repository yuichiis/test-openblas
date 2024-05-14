#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztptri)( /* LAPACKE_ztptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */
);
static PFNLAPACKE_ztptri _g_LAPACKE_ztptri = NULL;
lapack_int LAPACKE_ztptri(
    int            matrix_layout,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_complex_double *            ap
)
{
    if(_g_LAPACKE_ztptri==NULL) {
        _g_LAPACKE_ztptri = rindow_load_libopenblas_func("LAPACKE_ztptri"); 
        if(_g_LAPACKE_ztptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztptri(
        matrix_layout,
        uplo,
        diag,
        n,
        ap    
    );
}
