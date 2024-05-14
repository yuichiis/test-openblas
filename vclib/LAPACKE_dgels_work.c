#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgels_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgels_work)( /* LAPACKE_dgels_work */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dgels_work _g_LAPACKE_dgels_work = NULL;
lapack_int LAPACKE_dgels_work(
    int            matrix_layout,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nrhs,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dgels_work==NULL) {
        _g_LAPACKE_dgels_work = rindow_load_libopenblas_func("LAPACKE_dgels_work"); 
        if(_g_LAPACKE_dgels_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgels_work(
        matrix_layout,
        trans,
        m,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb,
        work,
        lwork    
    );
}
