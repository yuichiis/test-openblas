#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slatms_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slatms_work)( /* LAPACKE_slatms_work */
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
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* work */
);
static PFNLAPACKE_slatms_work _g_LAPACKE_slatms_work = NULL;
lapack_int LAPACKE_slatms_work(
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
    float *            a,
    lapack_int            lda,
    float *            work
)
{
    if(_g_LAPACKE_slatms_work==NULL) {
        _g_LAPACKE_slatms_work = rindow_load_libopenblas_func("LAPACKE_slatms_work"); 
        if(_g_LAPACKE_slatms_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slatms_work(
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
