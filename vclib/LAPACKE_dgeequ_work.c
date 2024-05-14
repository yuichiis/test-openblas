#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgeequ_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgeequ_work)( /* LAPACKE_dgeequ_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* r */,
    double *            /* c */,
    double *            /* rowcnd */,
    double *            /* colcnd */,
    double *            /* amax */
);
static PFNLAPACKE_dgeequ_work _g_LAPACKE_dgeequ_work = NULL;
lapack_int LAPACKE_dgeequ_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double *            r,
    double *            c,
    double *            rowcnd,
    double *            colcnd,
    double *            amax
)
{
    if(_g_LAPACKE_dgeequ_work==NULL) {
        _g_LAPACKE_dgeequ_work = rindow_load_libopenblas_func("LAPACKE_dgeequ_work"); 
        if(_g_LAPACKE_dgeequ_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgeequ_work(
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
