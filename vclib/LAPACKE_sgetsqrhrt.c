#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgetsqrhrt not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgetsqrhrt)( /* LAPACKE_sgetsqrhrt */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* mb1 */,
    lapack_int            /* nb1 */,
    lapack_int            /* nb2 */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_sgetsqrhrt _g_LAPACKE_sgetsqrhrt = NULL;
lapack_int LAPACKE_sgetsqrhrt(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            mb1,
    lapack_int            nb1,
    lapack_int            nb2,
    float *            a,
    lapack_int            lda,
    float *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_sgetsqrhrt==NULL) {
        _g_LAPACKE_sgetsqrhrt = rindow_load_libopenblas_func("LAPACKE_sgetsqrhrt"); 
        if(_g_LAPACKE_sgetsqrhrt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgetsqrhrt(
        matrix_layout,
        m,
        n,
        mb1,
        nb1,
        nb2,
        a,
        lda,
        t,
        ldt    
    );
}
