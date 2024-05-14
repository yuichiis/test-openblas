#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctftri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctftri)( /* LAPACKE_ctftri */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */
);
static PFNLAPACKE_ctftri _g_LAPACKE_ctftri = NULL;
lapack_int LAPACKE_ctftri(
    int            matrix_layout,
    char            transr,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_complex_float *            a
)
{
    if(_g_LAPACKE_ctftri==NULL) {
        _g_LAPACKE_ctftri = rindow_load_libopenblas_func("LAPACKE_ctftri"); 
        if(_g_LAPACKE_ctftri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctftri(
        matrix_layout,
        transr,
        uplo,
        diag,
        n,
        a    
    );
}
