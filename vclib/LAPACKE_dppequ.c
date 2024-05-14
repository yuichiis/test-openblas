#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dppequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dppequ)( /* LAPACKE_dppequ */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* ap */,
    double *            /* s */,
    double *            /* scond */,
    double *            /* amax */
);
static PFNLAPACKE_dppequ _g_LAPACKE_dppequ = NULL;
lapack_int LAPACKE_dppequ(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const double *            ap,
    double *            s,
    double *            scond,
    double *            amax
)
{
    if(_g_LAPACKE_dppequ==NULL) {
        _g_LAPACKE_dppequ = rindow_load_libopenblas_func("LAPACKE_dppequ"); 
        if(_g_LAPACKE_dppequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dppequ(
        matrix_layout,
        uplo,
        n,
        ap,
        s,
        scond,
        amax    
    );
}
