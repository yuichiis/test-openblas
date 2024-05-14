#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zungtr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zungtr_work)( /* LAPACKE_zungtr_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_zungtr_work _g_LAPACKE_zungtr_work = NULL;
lapack_int LAPACKE_zungtr_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            tau,
    lapack_complex_double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_zungtr_work==NULL) {
        _g_LAPACKE_zungtr_work = rindow_load_libopenblas_func("LAPACKE_zungtr_work"); 
        if(_g_LAPACKE_zungtr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zungtr_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        tau,
        work,
        lwork    
    );
}
