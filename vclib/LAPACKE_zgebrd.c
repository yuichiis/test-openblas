#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgebrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgebrd)( /* LAPACKE_zgebrd */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* d */,
    double *            /* e */,
    lapack_complex_double *            /* tauq */,
    lapack_complex_double *            /* taup */
);
static PFNLAPACKE_zgebrd _g_LAPACKE_zgebrd = NULL;
lapack_int LAPACKE_zgebrd(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    double *            d,
    double *            e,
    lapack_complex_double *            tauq,
    lapack_complex_double *            taup
)
{
    if(_g_LAPACKE_zgebrd==NULL) {
        _g_LAPACKE_zgebrd = rindow_load_libopenblas_func("LAPACKE_zgebrd"); 
        if(_g_LAPACKE_zgebrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgebrd(
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
