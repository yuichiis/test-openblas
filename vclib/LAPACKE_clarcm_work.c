#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clarcm_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clarcm_work)( /* LAPACKE_clarcm_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* work */
);
static PFNLAPACKE_clarcm_work _g_LAPACKE_clarcm_work = NULL;
lapack_int LAPACKE_clarcm_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            c,
    lapack_int            ldc,
    float *            work
)
{
    if(_g_LAPACKE_clarcm_work==NULL) {
        _g_LAPACKE_clarcm_work = rindow_load_libopenblas_func("LAPACKE_clarcm_work"); 
        if(_g_LAPACKE_clarcm_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clarcm_work(
        matrix_layout,
        m,
        n,
        a,
        lda,
        b,
        ldb,
        c,
        ldc,
        work    
    );
}
