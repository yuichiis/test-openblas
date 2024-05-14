#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgetsqrhrt_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgetsqrhrt_work)( /* LAPACKE_dgetsqrhrt_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* mb1 */,
    lapack_int            /* nb1 */,
    lapack_int            /* nb2 */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* t */,
    lapack_int            /* ldt */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dgetsqrhrt_work _g_LAPACKE_dgetsqrhrt_work = NULL;
lapack_int LAPACKE_dgetsqrhrt_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            mb1,
    lapack_int            nb1,
    lapack_int            nb2,
    double *            a,
    lapack_int            lda,
    double *            t,
    lapack_int            ldt,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dgetsqrhrt_work==NULL) {
        _g_LAPACKE_dgetsqrhrt_work = rindow_load_libopenblas_func("LAPACKE_dgetsqrhrt_work"); 
        if(_g_LAPACKE_dgetsqrhrt_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgetsqrhrt_work(
        matrix_layout,
        m,
        n,
        mb1,
        nb1,
        nb2,
        a,
        lda,
        t,
        ldt,
        work,
        lwork    
    );
}
