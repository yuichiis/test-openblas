#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgbtrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgbtrf)( /* LAPACKE_zgbtrf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_zgbtrf _g_LAPACKE_zgbtrf = NULL;
lapack_int LAPACKE_zgbtrf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_complex_double *            ab,
    lapack_int            ldab,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_zgbtrf==NULL) {
        _g_LAPACKE_zgbtrf = rindow_load_libopenblas_func("LAPACKE_zgbtrf"); 
        if(_g_LAPACKE_zgbtrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgbtrf(
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
