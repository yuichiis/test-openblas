#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cunmlq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cunmlq)( /* LAPACKE_cunmlq */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* tau */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_cunmlq _g_LAPACKE_cunmlq = NULL;
lapack_int LAPACKE_cunmlq(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            tau,
    lapack_complex_float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_cunmlq==NULL) {
        _g_LAPACKE_cunmlq = rindow_load_libopenblas_func("LAPACKE_cunmlq"); 
        if(_g_LAPACKE_cunmlq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cunmlq(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        a,
        lda,
        tau,
        c,
        ldc    
    );
}
