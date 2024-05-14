#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggbal not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggbal)( /* LAPACKE_dggbal */
    int            /* matrix_layout */,
    char            /* job */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    double *            /* lscale */,
    double *            /* rscale */
);
static PFNLAPACKE_dggbal _g_LAPACKE_dggbal = NULL;
lapack_int LAPACKE_dggbal(
    int            matrix_layout,
    char            job,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    lapack_int *            ilo,
    lapack_int *            ihi,
    double *            lscale,
    double *            rscale
)
{
    if(_g_LAPACKE_dggbal==NULL) {
        _g_LAPACKE_dggbal = rindow_load_libopenblas_func("LAPACKE_dggbal"); 
        if(_g_LAPACKE_dggbal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggbal(
        matrix_layout,
        job,
        n,
        a,
        lda,
        b,
        ldb,
        ilo,
        ihi,
        lscale,
        rscale    
    );
}
