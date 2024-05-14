#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlatms_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlatms_work)( /* LAPACKE_dlatms_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    char            /* dist */,
    lapack_int *            /* iseed */,
    char            /* sym */,
    double *            /* d */,
    lapack_int            /* mode */,
    double            /* cond */,
    double            /* dmax */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    char            /* pack */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* work */
);
static PFNLAPACKE_dlatms_work _g_LAPACKE_dlatms_work = NULL;
lapack_int LAPACKE_dlatms_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    char            dist,
    lapack_int *            iseed,
    char            sym,
    double *            d,
    lapack_int            mode,
    double            cond,
    double            dmax,
    lapack_int            kl,
    lapack_int            ku,
    char            pack,
    double *            a,
    lapack_int            lda,
    double *            work
)
{
    if(_g_LAPACKE_dlatms_work==NULL) {
        _g_LAPACKE_dlatms_work = rindow_load_libopenblas_func("LAPACKE_dlatms_work"); 
        if(_g_LAPACKE_dlatms_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlatms_work(
        matrix_layout,
        m,
        n,
        dist,
        iseed,
        sym,
        d,
        mode,
        cond,
        dmax,
        kl,
        ku,
        pack,
        a,
        lda,
        work    
    );
}
