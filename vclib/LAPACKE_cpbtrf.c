#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpbtrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpbtrf)( /* LAPACKE_cpbtrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */
);
static PFNLAPACKE_cpbtrf _g_LAPACKE_cpbtrf = NULL;
lapack_int LAPACKE_cpbtrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_complex_float *            ab,
    lapack_int            ldab
)
{
    if(_g_LAPACKE_cpbtrf==NULL) {
        _g_LAPACKE_cpbtrf = rindow_load_libopenblas_func("LAPACKE_cpbtrf"); 
        if(_g_LAPACKE_cpbtrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpbtrf(
        matrix_layout,
        uplo,
        n,
        kd,
        ab,
        ldab    
    );
}
