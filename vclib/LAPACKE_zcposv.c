#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zcposv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zcposv)( /* LAPACKE_zcposv */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    lapack_int *            /* iter */
);
static PFNLAPACKE_zcposv _g_LAPACKE_zcposv = NULL;
lapack_int LAPACKE_zcposv(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    lapack_int *            iter
)
{
    if(_g_LAPACKE_zcposv==NULL) {
        _g_LAPACKE_zcposv = rindow_load_libopenblas_func("LAPACKE_zcposv"); 
        if(_g_LAPACKE_zcposv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zcposv(
        matrix_layout,
        uplo,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb,
        x,
        ldx,
        iter    
    );
}
