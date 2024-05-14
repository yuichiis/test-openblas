#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spoequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spoequ)( /* LAPACKE_spoequ */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_spoequ _g_LAPACKE_spoequ = NULL;
lapack_int LAPACKE_spoequ(
    int            matrix_layout,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            s,
    float *            scond,
    float *            amax
)
{
    if(_g_LAPACKE_spoequ==NULL) {
        _g_LAPACKE_spoequ = rindow_load_libopenblas_func("LAPACKE_spoequ"); 
        if(_g_LAPACKE_spoequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spoequ(
        matrix_layout,
        n,
        a,
        lda,
        s,
        scond,
        amax    
    );
}
