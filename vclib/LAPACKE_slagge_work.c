#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slagge_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slagge_work)( /* LAPACKE_slagge_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const float *            /* d */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* iseed */,
    float *            /* work */
);
static PFNLAPACKE_slagge_work _g_LAPACKE_slagge_work = NULL;
lapack_int LAPACKE_slagge_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const float *            d,
    float *            a,
    lapack_int            lda,
    lapack_int *            iseed,
    float *            work
)
{
    if(_g_LAPACKE_slagge_work==NULL) {
        _g_LAPACKE_slagge_work = rindow_load_libopenblas_func("LAPACKE_slagge_work"); 
        if(_g_LAPACKE_slagge_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slagge_work(
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
