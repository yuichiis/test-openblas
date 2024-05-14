#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztftri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztftri)( /* LAPACKE_ztftri */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */
);
static PFNLAPACKE_ztftri _g_LAPACKE_ztftri = NULL;
lapack_int LAPACKE_ztftri(
    int            matrix_layout,
    char            transr,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_complex_double *            a
)
{
    if(_g_LAPACKE_ztftri==NULL) {
        _g_LAPACKE_ztftri = rindow_load_libopenblas_func("LAPACKE_ztftri"); 
        if(_g_LAPACKE_ztftri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztftri(
        matrix_layout,
        transr,
        uplo,
        diag,
        n,
        a    
    );
}
