#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spbtrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spbtrs)( /* LAPACKE_spbtrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    const float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_spbtrs _g_LAPACKE_spbtrs = NULL;
lapack_int LAPACKE_spbtrs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    const float *            ab,
    lapack_int            ldab,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_spbtrs==NULL) {
        _g_LAPACKE_spbtrs = rindow_load_libopenblas_func("LAPACKE_spbtrs"); 
        if(_g_LAPACKE_spbtrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spbtrs(
        matrix_layout,
        uplo,
        n,
        kd,
        nrhs,
        ab,
        ldab,
        b,
        ldb    
    );
}
