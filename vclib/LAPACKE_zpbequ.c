#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpbequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpbequ)( /* LAPACKE_zpbequ */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* s */,
    double *            /* scond */,
    double *            /* amax */
);
static PFNLAPACKE_zpbequ _g_LAPACKE_zpbequ = NULL;
lapack_int LAPACKE_zpbequ(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    const lapack_complex_double *            ab,
    lapack_int            ldab,
    double *            s,
    double *            scond,
    double *            amax
)
{
    if(_g_LAPACKE_zpbequ==NULL) {
        _g_LAPACKE_zpbequ = rindow_load_libopenblas_func("LAPACKE_zpbequ"); 
        if(_g_LAPACKE_zpbequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpbequ(
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
