#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctbtrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctbtrs)( /* LAPACKE_ctbtrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_ctbtrs _g_LAPACKE_ctbtrs = NULL;
lapack_int LAPACKE_ctbtrs(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    const lapack_complex_float *            ab,
    lapack_int            ldab,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_ctbtrs==NULL) {
        _g_LAPACKE_ctbtrs = rindow_load_libopenblas_func("LAPACKE_ctbtrs"); 
        if(_g_LAPACKE_ctbtrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctbtrs(
        matrix_layout,
        uplo,
        trans,
        diag,
        n,
        kd,
        nrhs,
        ab,
        ldab,
        b,
        ldb    
    );
}
