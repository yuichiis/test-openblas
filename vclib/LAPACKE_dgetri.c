#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgetri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgetri)( /* LAPACKE_dgetri */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_dgetri _g_LAPACKE_dgetri = NULL;
lapack_int LAPACKE_dgetri(
    int            matrix_layout,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_dgetri==NULL) {
        _g_LAPACKE_dgetri = rindow_load_libopenblas_func("LAPACKE_dgetri"); 
        if(_g_LAPACKE_dgetri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgetri(
        matrix_layout,
        n,
        a,
        lda,
        ipiv    
    );
}
