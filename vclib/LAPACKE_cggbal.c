#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggbal not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggbal)( /* LAPACKE_cggbal */
    int            /* matrix_layout */,
    char            /* job */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    float *            /* lscale */,
    float *            /* rscale */
);
static PFNLAPACKE_cggbal _g_LAPACKE_cggbal = NULL;
lapack_int LAPACKE_cggbal(
    int            matrix_layout,
    char            job,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_int *            ilo,
    lapack_int *            ihi,
    float *            lscale,
    float *            rscale
)
{
    if(_g_LAPACKE_cggbal==NULL) {
        _g_LAPACKE_cggbal = rindow_load_libopenblas_func("LAPACKE_cggbal"); 
        if(_g_LAPACKE_cggbal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggbal(
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
