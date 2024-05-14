#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zggbal_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zggbal_work)( /* LAPACKE_zggbal_work */
    int            /* matrix_layout */,
    char            /* job */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    double *            /* lscale */,
    double *            /* rscale */,
    double *            /* work */
);
static PFNLAPACKE_zggbal_work _g_LAPACKE_zggbal_work = NULL;
lapack_int LAPACKE_zggbal_work(
    int            matrix_layout,
    char            job,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_int *            ilo,
    lapack_int *            ihi,
    double *            lscale,
    double *            rscale,
    double *            work
)
{
    if(_g_LAPACKE_zggbal_work==NULL) {
        _g_LAPACKE_zggbal_work = rindow_load_libopenblas_func("LAPACKE_zggbal_work"); 
        if(_g_LAPACKE_zggbal_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zggbal_work(
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
        rscale,
        work    
    );
}
