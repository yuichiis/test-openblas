#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgetrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgetrf)( /* LAPACKE_sgetrf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_sgetrf _g_LAPACKE_sgetrf = NULL;
lapack_int LAPACKE_sgetrf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_sgetrf==NULL) {
        _g_LAPACKE_sgetrf = rindow_load_libopenblas_func("LAPACKE_sgetrf"); 
        if(_g_LAPACKE_sgetrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgetrf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        ipiv    
    );
}
