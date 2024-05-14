#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgbsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgbsv)( /* LAPACKE_sgbsv */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    lapack_int *            /* ipiv */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_sgbsv _g_LAPACKE_sgbsv = NULL;
lapack_int LAPACKE_sgbsv(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    float *            ab,
    lapack_int            ldab,
    lapack_int *            ipiv,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_sgbsv==NULL) {
        _g_LAPACKE_sgbsv = rindow_load_libopenblas_func("LAPACKE_sgbsv"); 
        if(_g_LAPACKE_sgbsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgbsv(
        matrix_layout,
        n,
        kl,
        ku,
        nrhs,
        ab,
        ldab,
        ipiv,
        b,
        ldb    
    );
}
