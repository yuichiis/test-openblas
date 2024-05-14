#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cheequb not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cheequb)( /* LAPACKE_cheequb */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_cheequb _g_LAPACKE_cheequb = NULL;
lapack_int LAPACKE_cheequb(
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
    if(_g_LAPACKE_cheequb==NULL) {
        _g_LAPACKE_cheequb = rindow_load_libopenblas_func("LAPACKE_cheequb"); 
        if(_g_LAPACKE_cheequb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cheequb(
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
