#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssyequb not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssyequb)( /* LAPACKE_ssyequb */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_ssyequb _g_LAPACKE_ssyequb = NULL;
lapack_int LAPACKE_ssyequb(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            s,
    float *            scond,
    float *            amax
)
{
    if(_g_LAPACKE_ssyequb==NULL) {
        _g_LAPACKE_ssyequb = rindow_load_libopenblas_func("LAPACKE_ssyequb"); 
        if(_g_LAPACKE_ssyequb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssyequb(
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
