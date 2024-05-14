#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spbsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spbsv)( /* LAPACKE_spbsv */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_spbsv _g_LAPACKE_spbsv = NULL;
lapack_int LAPACKE_spbsv(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    float *            ab,
    lapack_int            ldab,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_spbsv==NULL) {
        _g_LAPACKE_spbsv = rindow_load_libopenblas_func("LAPACKE_spbsv"); 
        if(_g_LAPACKE_spbsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spbsv(
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
