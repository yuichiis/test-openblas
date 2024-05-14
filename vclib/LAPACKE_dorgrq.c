#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dorgrq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dorgrq)( /* LAPACKE_dorgrq */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */
);
static PFNLAPACKE_dorgrq _g_LAPACKE_dorgrq = NULL;
lapack_int LAPACKE_dorgrq(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    double *            a,
    lapack_int            lda,
    const double *            tau
)
{
    if(_g_LAPACKE_dorgrq==NULL) {
        _g_LAPACKE_dorgrq = rindow_load_libopenblas_func("LAPACKE_dorgrq"); 
        if(_g_LAPACKE_dorgrq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dorgrq(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}
