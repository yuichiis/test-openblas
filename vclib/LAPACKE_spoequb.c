#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spoequb not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spoequb)( /* LAPACKE_spoequb */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_spoequb _g_LAPACKE_spoequb = NULL;
lapack_int LAPACKE_spoequb(
    int            matrix_layout,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            s,
    float *            scond,
    float *            amax
)
{
    if(_g_LAPACKE_spoequb==NULL) {
        _g_LAPACKE_spoequb = rindow_load_libopenblas_func("LAPACKE_spoequb"); 
        if(_g_LAPACKE_spoequb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spoequb(
        matrix_layout,
        n,
        a,
        lda,
        s,
        scond,
        amax    
    );
}
