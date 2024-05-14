#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slaswp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slaswp)( /* LAPACKE_slaswp */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int            /* k1 */,
    lapack_int            /* k2 */,
    const lapack_int *            /* ipiv */,
    lapack_int            /* incx */
);
static PFNLAPACKE_slaswp _g_LAPACKE_slaswp = NULL;
lapack_int LAPACKE_slaswp(
    int            matrix_layout,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    lapack_int            k1,
    lapack_int            k2,
    const lapack_int *            ipiv,
    lapack_int            incx
)
{
    if(_g_LAPACKE_slaswp==NULL) {
        _g_LAPACKE_slaswp = rindow_load_libopenblas_func("LAPACKE_slaswp"); 
        if(_g_LAPACKE_slaswp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slaswp(
        matrix_layout,
        n,
        a,
        lda,
        k1,
        k2,
        ipiv,
        incx    
    );
}
