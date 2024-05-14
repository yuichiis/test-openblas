#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strrfs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strrfs)( /* LAPACKE_strrfs */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    const float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_strrfs _g_LAPACKE_strrfs = NULL;
lapack_int LAPACKE_strrfs(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            a,
    lapack_int            lda,
    const float *            b,
    lapack_int            ldb,
    const float *            x,
    lapack_int            ldx,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_strrfs==NULL) {
        _g_LAPACKE_strrfs = rindow_load_libopenblas_func("LAPACKE_strrfs"); 
        if(_g_LAPACKE_strrfs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strrfs(
        matrix_layout,
        uplo,
        trans,
        diag,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb,
        x,
        ldx,
        ferr,
        berr    
    );
}
