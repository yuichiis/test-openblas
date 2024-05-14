#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeequ)( /* LAPACKE_sgeequ */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* r */,
    float *            /* c */,
    float *            /* rowcnd */,
    float *            /* colcnd */,
    float *            /* amax */
);
static PFNLAPACKE_sgeequ _g_LAPACKE_sgeequ = NULL;
lapack_int LAPACKE_sgeequ(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            r,
    float *            c,
    float *            rowcnd,
    float *            colcnd,
    float *            amax
)
{
    if(_g_LAPACKE_sgeequ==NULL) {
        _g_LAPACKE_sgeequ = rindow_load_libopenblas_func("LAPACKE_sgeequ"); 
        if(_g_LAPACKE_sgeequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeequ(
        matrix_layout,
        m,
        n,
        a,
        lda,
        r,
        c,
        rowcnd,
        colcnd,
        amax    
    );
}
