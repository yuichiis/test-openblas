#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgecon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgecon)( /* LAPACKE_sgecon */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_sgecon _g_LAPACKE_sgecon = NULL;
lapack_int LAPACKE_sgecon(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_sgecon==NULL) {
        _g_LAPACKE_sgecon = rindow_load_libopenblas_func("LAPACKE_sgecon"); 
        if(_g_LAPACKE_sgecon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgecon(
        matrix_layout,
        norm,
        n,
        a,
        lda,
        anorm,
        rcond    
    );
}
