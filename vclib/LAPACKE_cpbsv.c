#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpbsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpbsv)( /* LAPACKE_cpbsv */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cpbsv _g_LAPACKE_cpbsv = NULL;
lapack_int LAPACKE_cpbsv(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_int            nrhs,
    lapack_complex_float *            ab,
    lapack_int            ldab,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cpbsv==NULL) {
        _g_LAPACKE_cpbsv = rindow_load_libopenblas_func("LAPACKE_cpbsv"); 
        if(_g_LAPACKE_cpbsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpbsv(
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
