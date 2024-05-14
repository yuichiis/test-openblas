#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stftri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stftri)( /* LAPACKE_stftri */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    float *            /* a */
);
static PFNLAPACKE_stftri _g_LAPACKE_stftri = NULL;
lapack_int LAPACKE_stftri(
    int            matrix_layout,
    char            transr,
    char            uplo,
    char            diag,
    lapack_int            n,
    float *            a
)
{
    if(_g_LAPACKE_stftri==NULL) {
        _g_LAPACKE_stftri = rindow_load_libopenblas_func("LAPACKE_stftri"); 
        if(_g_LAPACKE_stftri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stftri(
        matrix_layout,
        transr,
        uplo,
        diag,
        n,
        a    
    );
}
