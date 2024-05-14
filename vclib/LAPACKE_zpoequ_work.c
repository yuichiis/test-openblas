#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpoequ_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpoequ_work)( /* LAPACKE_zpoequ_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* s */,
    double *            /* scond */,
    double *            /* amax */
);
static PFNLAPACKE_zpoequ_work _g_LAPACKE_zpoequ_work = NULL;
lapack_int LAPACKE_zpoequ_work(
    int            matrix_layout,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    double *            s,
    double *            scond,
    double *            amax
)
{
    if(_g_LAPACKE_zpoequ_work==NULL) {
        _g_LAPACKE_zpoequ_work = rindow_load_libopenblas_func("LAPACKE_zpoequ_work"); 
        if(_g_LAPACKE_zpoequ_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpoequ_work(
        matrix_layout,
        n,
        a,
        lda,
        s,
        scond,
        amax    
    );
}
