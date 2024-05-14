#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zggqrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zggqrf)( /* LAPACKE_zggqrf */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* taua */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* taub */
);
static PFNLAPACKE_zggqrf _g_LAPACKE_zggqrf = NULL;
lapack_int LAPACKE_zggqrf(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            m,
    lapack_int            p,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            taua,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            taub
)
{
    if(_g_LAPACKE_zggqrf==NULL) {
        _g_LAPACKE_zggqrf = rindow_load_libopenblas_func("LAPACKE_zggqrf"); 
        if(_g_LAPACKE_zggqrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zggqrf(
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
