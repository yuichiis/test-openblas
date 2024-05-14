#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgetsqrhrt not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgetsqrhrt)( /* LAPACKE_cgetsqrhrt */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* mb1 */,
    lapack_int            /* nb1 */,
    lapack_int            /* nb2 */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_cgetsqrhrt _g_LAPACKE_cgetsqrhrt = NULL;
lapack_int LAPACKE_cgetsqrhrt(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            mb1,
    lapack_int            nb1,
    lapack_int            nb2,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_cgetsqrhrt==NULL) {
        _g_LAPACKE_cgetsqrhrt = rindow_load_libopenblas_func("LAPACKE_cgetsqrhrt"); 
        if(_g_LAPACKE_cgetsqrhrt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgetsqrhrt(
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
