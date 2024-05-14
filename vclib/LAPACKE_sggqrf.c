#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggqrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggqrf)( /* LAPACKE_sggqrf */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* taua */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* taub */
);
static PFNLAPACKE_sggqrf _g_LAPACKE_sggqrf = NULL;
lapack_int LAPACKE_sggqrf(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            m,
    lapack_int            p,
    float *            a,
    lapack_int            lda,
    float *            taua,
    float *            b,
    lapack_int            ldb,
    float *            taub
)
{
    if(_g_LAPACKE_sggqrf==NULL) {
        _g_LAPACKE_sggqrf = rindow_load_libopenblas_func("LAPACKE_sggqrf"); 
        if(_g_LAPACKE_sggqrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggqrf(
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
