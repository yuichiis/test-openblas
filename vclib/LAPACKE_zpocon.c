#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpocon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpocon)( /* LAPACKE_zpocon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_zpocon _g_LAPACKE_zpocon = NULL;
lapack_int LAPACKE_zpocon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_zpocon==NULL) {
        _g_LAPACKE_zpocon = rindow_load_libopenblas_func("LAPACKE_zpocon"); 
        if(_g_LAPACKE_zpocon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpocon(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        anorm,
        rcond    
    );
}
