#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlagge_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlagge_work)( /* LAPACKE_dlagge_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const double *            /* d */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* iseed */,
    double *            /* work */
);
static PFNLAPACKE_dlagge_work _g_LAPACKE_dlagge_work = NULL;
lapack_int LAPACKE_dlagge_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const double *            d,
    double *            a,
    lapack_int            lda,
    lapack_int *            iseed,
    double *            work
)
{
    if(_g_LAPACKE_dlagge_work==NULL) {
        _g_LAPACKE_dlagge_work = rindow_load_libopenblas_func("LAPACKE_dlagge_work"); 
        if(_g_LAPACKE_dlagge_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlagge_work(
        matrix_layout,
        m,
        n,
        kl,
        ku,
        d,
        a,
        lda,
        iseed,
        work    
    );
}
