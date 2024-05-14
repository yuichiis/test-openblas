#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlaswp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlaswp)( /* LAPACKE_zlaswp */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_int            /* k1 */,
    lapack_int            /* k2 */,
    const lapack_int *            /* ipiv */,
    lapack_int            /* incx */
);
static PFNLAPACKE_zlaswp _g_LAPACKE_zlaswp = NULL;
lapack_int LAPACKE_zlaswp(
    int            matrix_layout,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_int            k1,
    lapack_int            k2,
    const lapack_int *            ipiv,
    lapack_int            incx
)
{
    if(_g_LAPACKE_zlaswp==NULL) {
        _g_LAPACKE_zlaswp = rindow_load_libopenblas_func("LAPACKE_zlaswp"); 
        if(_g_LAPACKE_zlaswp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlaswp(
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
