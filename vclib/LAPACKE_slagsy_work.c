#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slagsy_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slagsy_work)( /* LAPACKE_slagsy_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const float *            /* d */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* iseed */,
    float *            /* work */
);
static PFNLAPACKE_slagsy_work _g_LAPACKE_slagsy_work = NULL;
lapack_int LAPACKE_slagsy_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            k,
    const float *            d,
    float *            a,
    lapack_int            lda,
    lapack_int *            iseed,
    float *            work
)
{
    if(_g_LAPACKE_slagsy_work==NULL) {
        _g_LAPACKE_slagsy_work = rindow_load_libopenblas_func("LAPACKE_slagsy_work"); 
        if(_g_LAPACKE_slagsy_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slagsy_work(
        matrix_layout,
        n,
        k,
        d,
        a,
        lda,
        iseed,
        work    
    );
}
