#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztrtri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztrtri)( /* LAPACKE_ztrtri */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_ztrtri _g_LAPACKE_ztrtri = NULL;
lapack_int LAPACKE_ztrtri(
    int            matrix_layout,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_ztrtri==NULL) {
        _g_LAPACKE_ztrtri = rindow_load_libopenblas_func("LAPACKE_ztrtri"); 
        if(_g_LAPACKE_ztrtri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztrtri(
        matrix_layout,
        uplo,
        diag,
        n,
        a,
        lda    
    );
}
