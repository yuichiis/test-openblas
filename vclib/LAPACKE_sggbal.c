#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggbal not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggbal)( /* LAPACKE_sggbal */
    int            /* matrix_layout */,
    char            /* job */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    float *            /* lscale */,
    float *            /* rscale */
);
static PFNLAPACKE_sggbal _g_LAPACKE_sggbal = NULL;
lapack_int LAPACKE_sggbal(
    int            matrix_layout,
    char            job,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    lapack_int *            ilo,
    lapack_int *            ihi,
    float *            lscale,
    float *            rscale
)
{
    if(_g_LAPACKE_sggbal==NULL) {
        _g_LAPACKE_sggbal = rindow_load_libopenblas_func("LAPACKE_sggbal"); 
        if(_g_LAPACKE_sggbal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggbal(
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
