#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgetri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgetri)( /* LAPACKE_sgetri */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    const lapack_int *            /* ipiv */
);
static PFNLAPACKE_sgetri _g_LAPACKE_sgetri = NULL;
lapack_int LAPACKE_sgetri(
    int            matrix_layout,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    const lapack_int *            ipiv
)
{
    if(_g_LAPACKE_sgetri==NULL) {
        _g_LAPACKE_sgetri = rindow_load_libopenblas_func("LAPACKE_sgetri"); 
        if(_g_LAPACKE_sgetri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgetri(
        matrix_layout,
        n,
        a,
        lda,
        ipiv    
    );
}
