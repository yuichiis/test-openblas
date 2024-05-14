#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctptrs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctptrs_work)( /* LAPACKE_ctptrs_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const lapack_complex_float *            /* ap */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_ctptrs_work _g_LAPACKE_ctptrs_work = NULL;
lapack_int LAPACKE_ctptrs_work(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            nrhs,
    const lapack_complex_float *            ap,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_ctptrs_work==NULL) {
        _g_LAPACKE_ctptrs_work = rindow_load_libopenblas_func("LAPACKE_ctptrs_work"); 
        if(_g_LAPACKE_ctptrs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctptrs_work(
        matrix_layout,
        uplo,
        trans,
        diag,
        n,
        nrhs,
        ap,
        b,
        ldb    
    );
}
