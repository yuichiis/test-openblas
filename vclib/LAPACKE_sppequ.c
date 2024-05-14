#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sppequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sppequ)( /* LAPACKE_sppequ */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* ap */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_sppequ _g_LAPACKE_sppequ = NULL;
lapack_int LAPACKE_sppequ(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            ap,
    float *            s,
    float *            scond,
    float *            amax
)
{
    if(_g_LAPACKE_sppequ==NULL) {
        _g_LAPACKE_sppequ = rindow_load_libopenblas_func("LAPACKE_sppequ"); 
        if(_g_LAPACKE_sppequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sppequ(
        matrix_layout,
        uplo,
        n,
        ap,
        s,
        scond,
        amax    
    );
}
