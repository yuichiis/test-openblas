#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeqr)( /* LAPACKE_sgeqr */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* t */,
    lapack_int            /* tsize */
);
static PFNLAPACKE_sgeqr _g_LAPACKE_sgeqr = NULL;
lapack_int LAPACKE_sgeqr(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            t,
    lapack_int            tsize
)
{
    if(_g_LAPACKE_sgeqr==NULL) {
        _g_LAPACKE_sgeqr = rindow_load_libopenblas_func("LAPACKE_sgeqr"); 
        if(_g_LAPACKE_sgeqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeqr(
        matrix_layout,
        m,
        n,
        a,
        lda,
        t,
        tsize    
    );
}
