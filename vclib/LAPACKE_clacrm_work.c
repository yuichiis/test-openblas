#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clacrm_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clacrm_work)( /* LAPACKE_clacrm_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* work */
);
static PFNLAPACKE_clacrm_work _g_LAPACKE_clacrm_work = NULL;
lapack_int LAPACKE_clacrm_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const float *            b,
    lapack_int            ldb,
    lapack_complex_float *            c,
    lapack_int            ldc,
    float *            work
)
{
    if(_g_LAPACKE_clacrm_work==NULL) {
        _g_LAPACKE_clacrm_work = rindow_load_libopenblas_func("LAPACKE_clacrm_work"); 
        if(_g_LAPACKE_clacrm_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clacrm_work(
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
