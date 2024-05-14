#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggqrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggqrf)( /* LAPACKE_dggqrf */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* taua */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* taub */
);
static PFNLAPACKE_dggqrf _g_LAPACKE_dggqrf = NULL;
lapack_int LAPACKE_dggqrf(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            m,
    lapack_int            p,
    double *            a,
    lapack_int            lda,
    double *            taua,
    double *            b,
    lapack_int            ldb,
    double *            taub
)
{
    if(_g_LAPACKE_dggqrf==NULL) {
        _g_LAPACKE_dggqrf = rindow_load_libopenblas_func("LAPACKE_dggqrf"); 
        if(_g_LAPACKE_dggqrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggqrf(
        matrix_layout,
        n,
        m,
        p,
        a,
        lda,
        taua,
        b,
        ldb,
        taub    
    );
}
