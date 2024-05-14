#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpoequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpoequ)( /* LAPACKE_cpoequ */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_cpoequ _g_LAPACKE_cpoequ = NULL;
lapack_int LAPACKE_cpoequ(
    int            matrix_layout,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    float *            s,
    float *            scond,
    float *            amax
)
{
    if(_g_LAPACKE_cpoequ==NULL) {
        _g_LAPACKE_cpoequ = rindow_load_libopenblas_func("LAPACKE_cpoequ"); 
        if(_g_LAPACKE_cpoequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpoequ(
        matrix_layout,
        n,
        a,
        lda,
        s,
        scond,
        amax    
    );
}
