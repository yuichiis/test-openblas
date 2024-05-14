#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtrtrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtrtrs)( /* LAPACKE_dtrtrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dtrtrs _g_LAPACKE_dtrtrs = NULL;
lapack_int LAPACKE_dtrtrs(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            nrhs,
    const double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dtrtrs==NULL) {
        _g_LAPACKE_dtrtrs = rindow_load_libopenblas_func("LAPACKE_dtrtrs"); 
        if(_g_LAPACKE_dtrtrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtrtrs(
        matrix_layout,
        uplo,
        trans,
        diag,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb    
    );
}
