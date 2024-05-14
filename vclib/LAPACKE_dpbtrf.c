#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpbtrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpbtrf)( /* LAPACKE_dpbtrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    double *            /* ab */,
    lapack_int            /* ldab */
);
static PFNLAPACKE_dpbtrf _g_LAPACKE_dpbtrf = NULL;
lapack_int LAPACKE_dpbtrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    double *            ab,
    lapack_int            ldab
)
{
    if(_g_LAPACKE_dpbtrf==NULL) {
        _g_LAPACKE_dpbtrf = rindow_load_libopenblas_func("LAPACKE_dpbtrf"); 
        if(_g_LAPACKE_dpbtrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpbtrf(
        matrix_layout,
        uplo,
        n,
        kd,
        ab,
        ldab    
    );
}
