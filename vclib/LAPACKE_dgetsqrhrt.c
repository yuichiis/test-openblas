#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgetsqrhrt not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgetsqrhrt)( /* LAPACKE_dgetsqrhrt */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* mb1 */,
    lapack_int            /* nb1 */,
    lapack_int            /* nb2 */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_dgetsqrhrt _g_LAPACKE_dgetsqrhrt = NULL;
lapack_int LAPACKE_dgetsqrhrt(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            mb1,
    lapack_int            nb1,
    lapack_int            nb2,
    double *            a,
    lapack_int            lda,
    double *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_dgetsqrhrt==NULL) {
        _g_LAPACKE_dgetsqrhrt = rindow_load_libopenblas_func("LAPACKE_dgetsqrhrt"); 
        if(_g_LAPACKE_dgetsqrhrt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgetsqrhrt(
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
