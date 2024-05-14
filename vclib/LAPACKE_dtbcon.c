#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtbcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtbcon)( /* LAPACKE_dtbcon */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* rcond */
);
static PFNLAPACKE_dtbcon _g_LAPACKE_dtbcon = NULL;
lapack_int LAPACKE_dtbcon(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_int            kd,
    const double *            ab,
    lapack_int            ldab,
    double *            rcond
)
{
    if(_g_LAPACKE_dtbcon==NULL) {
        _g_LAPACKE_dtbcon = rindow_load_libopenblas_func("LAPACKE_dtbcon"); 
        if(_g_LAPACKE_dtbcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtbcon(
        matrix_layout,
        norm,
        uplo,
        diag,
        n,
        kd,
        ab,
        ldab,
        rcond    
    );
}
