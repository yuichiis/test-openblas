#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpoequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpoequ)( /* LAPACKE_dpoequ */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* s */,
    double *            /* scond */,
    double *            /* amax */
);
static PFNLAPACKE_dpoequ _g_LAPACKE_dpoequ = NULL;
lapack_int LAPACKE_dpoequ(
    int            matrix_layout,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double *            s,
    double *            scond,
    double *            amax
)
{
    if(_g_LAPACKE_dpoequ==NULL) {
        _g_LAPACKE_dpoequ = rindow_load_libopenblas_func("LAPACKE_dpoequ"); 
        if(_g_LAPACKE_dpoequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpoequ(
        matrix_layout,
        n,
        a,
        lda,
        s,
        scond,
        amax    
    );
}
