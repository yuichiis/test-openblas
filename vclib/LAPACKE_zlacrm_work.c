#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlacrm_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlacrm_work)( /* LAPACKE_zlacrm_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */,
    double *            /* work */
);
static PFNLAPACKE_zlacrm_work _g_LAPACKE_zlacrm_work = NULL;
lapack_int LAPACKE_zlacrm_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const double *            b,
    lapack_int            ldb,
    lapack_complex_double *            c,
    lapack_int            ldc,
    double *            work
)
{
    if(_g_LAPACKE_zlacrm_work==NULL) {
        _g_LAPACKE_zlacrm_work = rindow_load_libopenblas_func("LAPACKE_zlacrm_work"); 
        if(_g_LAPACKE_zlacrm_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlacrm_work(
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
