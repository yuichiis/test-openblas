#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsygvd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsygvd)( /* LAPACKE_dsygvd */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* w */
);
static PFNLAPACKE_dsygvd _g_LAPACKE_dsygvd = NULL;
lapack_int LAPACKE_dsygvd(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            w
)
{
    if(_g_LAPACKE_dsygvd==NULL) {
        _g_LAPACKE_dsygvd = rindow_load_libopenblas_func("LAPACKE_dsygvd"); 
        if(_g_LAPACKE_dsygvd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsygvd(
        matrix_layout,
        itype,
        jobz,
        uplo,
        n,
        a,
        lda,
        b,
        ldb,
        w    
    );
}
