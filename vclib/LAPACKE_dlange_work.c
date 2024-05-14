#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlange_work not found\n";
typedef double (CALLBACK* PFNLAPACKE_dlange_work)( /* LAPACKE_dlange_work */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* work */
);
static PFNLAPACKE_dlange_work _g_LAPACKE_dlange_work = NULL;
double LAPACKE_dlange_work(
    int            matrix_layout,
    char            norm,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double *            work
)
{
    if(_g_LAPACKE_dlange_work==NULL) {
        _g_LAPACKE_dlange_work = rindow_load_libopenblas_func("LAPACKE_dlange_work"); 
        if(_g_LAPACKE_dlange_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlange_work(
        matrix_layout,
        norm,
        m,
        n,
        a,
        lda,
        work    
    );
}
