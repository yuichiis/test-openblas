#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpocon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpocon)( /* LAPACKE_dpocon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_dpocon _g_LAPACKE_dpocon = NULL;
lapack_int LAPACKE_dpocon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_dpocon==NULL) {
        _g_LAPACKE_dpocon = rindow_load_libopenblas_func("LAPACKE_dpocon"); 
        if(_g_LAPACKE_dpocon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpocon(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        anorm,
        rcond    
    );
}
