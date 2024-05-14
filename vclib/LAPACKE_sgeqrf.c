#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeqrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeqrf)( /* LAPACKE_sgeqrf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* tau */
);
static PFNLAPACKE_sgeqrf _g_LAPACKE_sgeqrf = NULL;
lapack_int LAPACKE_sgeqrf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            tau
)
{
    if(_g_LAPACKE_sgeqrf==NULL) {
        _g_LAPACKE_sgeqrf = rindow_load_libopenblas_func("LAPACKE_sgeqrf"); 
        if(_g_LAPACKE_sgeqrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeqrf(
        matrix_layout,
        m,
        n,
        a,
        lda,
        tau    
    );
}
