#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spbtrf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spbtrf)( /* LAPACKE_spbtrf */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    float *            /* ab */,
    lapack_int            /* ldab */
);
static PFNLAPACKE_spbtrf _g_LAPACKE_spbtrf = NULL;
lapack_int LAPACKE_spbtrf(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    float *            ab,
    lapack_int            ldab
)
{
    if(_g_LAPACKE_spbtrf==NULL) {
        _g_LAPACKE_spbtrf = rindow_load_libopenblas_func("LAPACKE_spbtrf"); 
        if(_g_LAPACKE_spbtrf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spbtrf(
        matrix_layout,
        uplo,
        n,
        kd,
        ab,
        ldab    
    );
}
