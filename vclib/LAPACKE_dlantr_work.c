#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlantr_work not found\n";
typedef double (CALLBACK* PFNLAPACKE_dlantr_work)( /* LAPACKE_dlantr_work */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* work */
);
static PFNLAPACKE_dlantr_work _g_LAPACKE_dlantr_work = NULL;
double LAPACKE_dlantr_work(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double *            work
)
{
    if(_g_LAPACKE_dlantr_work==NULL) {
        _g_LAPACKE_dlantr_work = rindow_load_libopenblas_func("LAPACKE_dlantr_work"); 
        if(_g_LAPACKE_dlantr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlantr_work(
        matrix_layout,
        norm,
        uplo,
        diag,
        m,
        n,
        a,
        lda,
        work    
    );
}
