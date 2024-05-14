#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stbtrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stbtrs)( /* LAPACKE_stbtrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    const float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_stbtrs _g_LAPACKE_stbtrs = NULL;
lapack_int LAPACKE_stbtrs(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    const float *            ab,
    lapack_int            ldab,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_stbtrs==NULL) {
        _g_LAPACKE_stbtrs = rindow_load_libopenblas_func("LAPACKE_stbtrs"); 
        if(_g_LAPACKE_stbtrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stbtrs(
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
