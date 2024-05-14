#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgebrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgebrd)( /* LAPACKE_cgebrd */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* d */,
    float *            /* e */,
    lapack_complex_float *            /* tauq */,
    lapack_complex_float *            /* taup */
);
static PFNLAPACKE_cgebrd _g_LAPACKE_cgebrd = NULL;
lapack_int LAPACKE_cgebrd(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    float *            d,
    float *            e,
    lapack_complex_float *            tauq,
    lapack_complex_float *            taup
)
{
    if(_g_LAPACKE_cgebrd==NULL) {
        _g_LAPACKE_cgebrd = rindow_load_libopenblas_func("LAPACKE_cgebrd"); 
        if(_g_LAPACKE_cgebrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgebrd(
        matrix_layout,
        m,
        n,
        a,
        lda,
        d,
        e,
        tauq,
        taup    
    );
}
