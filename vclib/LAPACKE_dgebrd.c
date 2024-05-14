#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgebrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgebrd)( /* LAPACKE_dgebrd */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* d */,
    double *            /* e */,
    double *            /* tauq */,
    double *            /* taup */
);
static PFNLAPACKE_dgebrd _g_LAPACKE_dgebrd = NULL;
lapack_int LAPACKE_dgebrd(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            d,
    double *            e,
    double *            tauq,
    double *            taup
)
{
    if(_g_LAPACKE_dgebrd==NULL) {
        _g_LAPACKE_dgebrd = rindow_load_libopenblas_func("LAPACKE_dgebrd"); 
        if(_g_LAPACKE_dgebrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgebrd(
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
