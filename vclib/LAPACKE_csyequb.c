#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csyequb not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csyequb)( /* LAPACKE_csyequb */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_csyequb _g_LAPACKE_csyequb = NULL;
lapack_int LAPACKE_csyequb(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    float *            s,
    float *            scond,
    float *            amax
)
{
    if(_g_LAPACKE_csyequb==NULL) {
        _g_LAPACKE_csyequb = rindow_load_libopenblas_func("LAPACKE_csyequb"); 
        if(_g_LAPACKE_csyequb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csyequb(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        s,
        scond,
        amax    
    );
}
