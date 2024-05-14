#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgbtrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgbtrf)( /* LAPACKE_sgbtrf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_sgbtrf _g_LAPACKE_sgbtrf = NULL;
lapack_int LAPACKE_sgbtrf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    float *            ab,
    lapack_int            ldab,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_sgbtrf==NULL) {
        _g_LAPACKE_sgbtrf = rindow_load_libopenblas_func("LAPACKE_sgbtrf"); 
        if(_g_LAPACKE_sgbtrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgbtrf(
        matrix_layout,
        m,
        n,
        kl,
        ku,
        ab,
        ldab,
        ipiv    
    );
}
