#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spbequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spbequ)( /* LAPACKE_spbequ */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_spbequ _g_LAPACKE_spbequ = NULL;
lapack_int LAPACKE_spbequ(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    const float *            ab,
    lapack_int            ldab,
    float *            s,
    float *            scond,
    float *            amax
)
{
    if(_g_LAPACKE_spbequ==NULL) {
        _g_LAPACKE_spbequ = rindow_load_libopenblas_func("LAPACKE_spbequ"); 
        if(_g_LAPACKE_spbequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spbequ(
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
