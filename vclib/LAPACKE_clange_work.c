#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clange_work not found\n";
typedef float (CALLBACK* PFNLAPACKE_clange_work)( /* LAPACKE_clange_work */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* work */
);
static PFNLAPACKE_clange_work _g_LAPACKE_clange_work = NULL;
float LAPACKE_clange_work(
    int            matrix_layout,
    char            norm,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    float *            work
)
{
    if(_g_LAPACKE_clange_work==NULL) {
        _g_LAPACKE_clange_work = rindow_load_libopenblas_func("LAPACKE_clange_work"); 
        if(_g_LAPACKE_clange_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clange_work(
        matrix_layout,
        norm,
        m,
        n,
        a,
        lda,
        work    
    );
}
