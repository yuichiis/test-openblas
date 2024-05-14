#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slantr_work not found\n";
typedef float (CALLBACK* PFNLAPACKE_slantr_work)( /* LAPACKE_slantr_work */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* work */
);
static PFNLAPACKE_slantr_work _g_LAPACKE_slantr_work = NULL;
float LAPACKE_slantr_work(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            work
)
{
    if(_g_LAPACKE_slantr_work==NULL) {
        _g_LAPACKE_slantr_work = rindow_load_libopenblas_func("LAPACKE_slantr_work"); 
        if(_g_LAPACKE_slantr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slantr_work(
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
