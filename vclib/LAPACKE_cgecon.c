#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgecon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgecon)( /* LAPACKE_cgecon */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_cgecon _g_LAPACKE_cgecon = NULL;
lapack_int LAPACKE_cgecon(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_cgecon==NULL) {
        _g_LAPACKE_cgecon = rindow_load_libopenblas_func("LAPACKE_cgecon"); 
        if(_g_LAPACKE_cgecon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgecon(
        matrix_layout,
        norm,
        n,
        a,
        lda,
        anorm,
        rcond    
    );
}
