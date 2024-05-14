#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpbcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpbcon)( /* LAPACKE_dpbcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const double *            /* ab */,
    lapack_int            /* ldab */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_dpbcon _g_LAPACKE_dpbcon = NULL;
lapack_int LAPACKE_dpbcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    const double *            ab,
    lapack_int            ldab,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_dpbcon==NULL) {
        _g_LAPACKE_dpbcon = rindow_load_libopenblas_func("LAPACKE_dpbcon"); 
        if(_g_LAPACKE_dpbcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpbcon(
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
