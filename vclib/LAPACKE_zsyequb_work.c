#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zsyequb_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zsyequb_work)( /* LAPACKE_zsyequb_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* s */,
    double *            /* scond */,
    double *            /* amax */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zsyequb_work _g_LAPACKE_zsyequb_work = NULL;
lapack_int LAPACKE_zsyequb_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    double *            s,
    double *            scond,
    double *            amax,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zsyequb_work==NULL) {
        _g_LAPACKE_zsyequb_work = rindow_load_libopenblas_func("LAPACKE_zsyequb_work"); 
        if(_g_LAPACKE_zsyequb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zsyequb_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        s,
        scond,
        amax,
        work    
    );
}
