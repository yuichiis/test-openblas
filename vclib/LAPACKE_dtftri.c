#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtftri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtftri)( /* LAPACKE_dtftri */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    double *            /* a */
);
static PFNLAPACKE_dtftri _g_LAPACKE_dtftri = NULL;
lapack_int LAPACKE_dtftri(
    int            matrix_layout,
    char            transr,
    char            uplo,
    char            diag,
    lapack_int            n,
    double *            a
)
{
    if(_g_LAPACKE_dtftri==NULL) {
        _g_LAPACKE_dtftri = rindow_load_libopenblas_func("LAPACKE_dtftri"); 
        if(_g_LAPACKE_dtftri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtftri(
        matrix_layout,
        transr,
        uplo,
        diag,
        n,
        a    
    );
}
