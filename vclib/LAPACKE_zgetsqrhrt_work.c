#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgetsqrhrt_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgetsqrhrt_work)( /* LAPACKE_zgetsqrhrt_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* mb1 */,
    lapack_int            /* nb1 */,
    lapack_int            /* nb2 */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_zgetsqrhrt_work _g_LAPACKE_zgetsqrhrt_work = NULL;
lapack_int LAPACKE_zgetsqrhrt_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            mb1,
    lapack_int            nb1,
    lapack_int            nb2,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            t,
    lapack_int            ldt,
    lapack_complex_double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_zgetsqrhrt_work==NULL) {
        _g_LAPACKE_zgetsqrhrt_work = rindow_load_libopenblas_func("LAPACKE_zgetsqrhrt_work"); 
        if(_g_LAPACKE_zgetsqrhrt_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgetsqrhrt_work(
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
