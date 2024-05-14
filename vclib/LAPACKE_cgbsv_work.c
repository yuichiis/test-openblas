#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgbsv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgbsv_work)( /* LAPACKE_cgbsv_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    lapack_int *            /* ipiv */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cgbsv_work _g_LAPACKE_cgbsv_work = NULL;
lapack_int LAPACKE_cgbsv_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    lapack_complex_float *            ab,
    lapack_int            ldab,
    lapack_int *            ipiv,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cgbsv_work==NULL) {
        _g_LAPACKE_cgbsv_work = rindow_load_libopenblas_func("LAPACKE_cgbsv_work"); 
        if(_g_LAPACKE_cgbsv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgbsv_work(
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
