#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cppequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cppequ)( /* LAPACKE_cppequ */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* ap */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_cppequ _g_LAPACKE_cppequ = NULL;
lapack_int LAPACKE_cppequ(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            ap,
    float *            s,
    float *            scond,
    float *            amax
)
{
    if(_g_LAPACKE_cppequ==NULL) {
        _g_LAPACKE_cppequ = rindow_load_libopenblas_func("LAPACKE_cppequ"); 
        if(_g_LAPACKE_cppequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cppequ(
        matrix_layout,
        uplo,
        n,
        ap,
        s,
        scond,
        amax    
    );
}
