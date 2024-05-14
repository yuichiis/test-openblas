#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strttp_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strttp_work)( /* LAPACKE_strttp_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* ap */
);
static PFNLAPACKE_strttp_work _g_LAPACKE_strttp_work = NULL;
lapack_int LAPACKE_strttp_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            ap
)
{
    if(_g_LAPACKE_strttp_work==NULL) {
        _g_LAPACKE_strttp_work = rindow_load_libopenblas_func("LAPACKE_strttp_work"); 
        if(_g_LAPACKE_strttp_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strttp_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        ap    
    );
}
