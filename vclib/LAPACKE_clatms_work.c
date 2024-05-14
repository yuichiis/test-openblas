#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clatms_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clatms_work)( /* LAPACKE_clatms_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    char            /* dist */,
    lapack_int *            /* iseed */,
    char            /* sym */,
    float *            /* d */,
    lapack_int            /* mode */,
    float            /* cond */,
    float            /* dmax */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    char            /* pack */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* work */
);
static PFNLAPACKE_clatms_work _g_LAPACKE_clatms_work = NULL;
lapack_int LAPACKE_clatms_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    char            dist,
    lapack_int *            iseed,
    char            sym,
    float *            d,
    lapack_int            mode,
    float            cond,
    float            dmax,
    lapack_int            kl,
    lapack_int            ku,
    char            pack,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            work
)
{
    if(_g_LAPACKE_clatms_work==NULL) {
        _g_LAPACKE_clatms_work = rindow_load_libopenblas_func("LAPACKE_clatms_work"); 
        if(_g_LAPACKE_clatms_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clatms_work(
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
