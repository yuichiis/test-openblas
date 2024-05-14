#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgetri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgetri)( /* LAPACKE_zgetri */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_zgetri _g_LAPACKE_zgetri = NULL;
lapack_int LAPACKE_zgetri(
    int            matrix_layout,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_zgetri==NULL) {
        _g_LAPACKE_zgetri = rindow_load_libopenblas_func("LAPACKE_zgetri"); 
        if(_g_LAPACKE_zgetri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgetri(
        matrix_layout,
        n,
        a,
        lda,
        ipiv    
    );
}
