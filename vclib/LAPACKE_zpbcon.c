#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpbcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpbcon)( /* LAPACKE_zpbcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_zpbcon _g_LAPACKE_zpbcon = NULL;
lapack_int LAPACKE_zpbcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    const lapack_complex_double *            ab,
    lapack_int            ldab,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_zpbcon==NULL) {
        _g_LAPACKE_zpbcon = rindow_load_libopenblas_func("LAPACKE_zpbcon"); 
        if(_g_LAPACKE_zpbcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpbcon(
        matrix_layout,
        uplo,
        n,
        kd,
        ab,
        ldab,
        anorm,
        rcond    
    );
}
