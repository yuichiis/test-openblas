#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slansy_work not found\n";
typedef float (CALLBACK* PFNLAPACKE_slansy_work)( /* LAPACKE_slansy_work */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* work */
);
static PFNLAPACKE_slansy_work _g_LAPACKE_slansy_work = NULL;
float LAPACKE_slansy_work(
    int            matrix_layout,
    char            norm,
    char            uplo,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            work
)
{
    if(_g_LAPACKE_slansy_work==NULL) {
        _g_LAPACKE_slansy_work = rindow_load_libopenblas_func("LAPACKE_slansy_work"); 
        if(_g_LAPACKE_slansy_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slansy_work(
        matrix_layout,
        norm,
        uplo,
        n,
        a,
        lda,
        work    
    );
}
