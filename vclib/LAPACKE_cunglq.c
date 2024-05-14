#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cunglq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cunglq)( /* LAPACKE_cunglq */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* tau */
);
static PFNLAPACKE_cunglq _g_LAPACKE_cunglq = NULL;
lapack_int LAPACKE_cunglq(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            tau
)
{
    if(_g_LAPACKE_cunglq==NULL) {
        _g_LAPACKE_cunglq = rindow_load_libopenblas_func("LAPACKE_cunglq"); 
        if(_g_LAPACKE_cunglq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cunglq(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}
