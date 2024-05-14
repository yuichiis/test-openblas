#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpbtrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpbtrf)( /* LAPACKE_zpbtrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */
);
static PFNLAPACKE_zpbtrf _g_LAPACKE_zpbtrf = NULL;
lapack_int LAPACKE_zpbtrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_complex_double *            ab,
    lapack_int            ldab
)
{
    if(_g_LAPACKE_zpbtrf==NULL) {
        _g_LAPACKE_zpbtrf = rindow_load_libopenblas_func("LAPACKE_zpbtrf"); 
        if(_g_LAPACKE_zpbtrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpbtrf(
        matrix_layout,
        uplo,
        n,
        kd,
        ab,
        ldab    
    );
}
