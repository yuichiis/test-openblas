#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpbequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpbequ)( /* LAPACKE_dpbequ */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* s */,
    double *            /* scond */,
    double *            /* amax */
);
static PFNLAPACKE_dpbequ _g_LAPACKE_dpbequ = NULL;
lapack_int LAPACKE_dpbequ(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    const double *            ab,
    lapack_int            ldab,
    double *            s,
    double *            scond,
    double *            amax
)
{
    if(_g_LAPACKE_dpbequ==NULL) {
        _g_LAPACKE_dpbequ = rindow_load_libopenblas_func("LAPACKE_dpbequ"); 
        if(_g_LAPACKE_dpbequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpbequ(
        matrix_layout,
        uplo,
        n,
        kd,
        ab,
        ldab,
        s,
        scond,
        amax    
    );
}
