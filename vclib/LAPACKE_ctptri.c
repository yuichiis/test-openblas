#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctptri)( /* LAPACKE_ctptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */
);
static PFNLAPACKE_ctptri _g_LAPACKE_ctptri = NULL;
lapack_int LAPACKE_ctptri(
    int            matrix_layout,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_complex_float *            ap
)
{
    if(_g_LAPACKE_ctptri==NULL) {
        _g_LAPACKE_ctptri = rindow_load_libopenblas_func("LAPACKE_ctptri"); 
        if(_g_LAPACKE_ctptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctptri(
        matrix_layout,
        uplo,
        diag,
        n,
        ap    
    );
}
