#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgelq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgelq)( /* LAPACKE_cgelq */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* t */,
    lapack_int            /* tsize */
);
static PFNLAPACKE_cgelq _g_LAPACKE_cgelq = NULL;
lapack_int LAPACKE_cgelq(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            t,
    lapack_int            tsize
)
{
    if(_g_LAPACKE_cgelq==NULL) {
        _g_LAPACKE_cgelq = rindow_load_libopenblas_func("LAPACKE_cgelq"); 
        if(_g_LAPACKE_cgelq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgelq(
        matrix_layout,
        m,
        n,
        a,
        lda,
        t,
        tsize    
    );
}
