#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpbcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpbcon)( /* LAPACKE_cpbcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_cpbcon _g_LAPACKE_cpbcon = NULL;
lapack_int LAPACKE_cpbcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    const lapack_complex_float *            ab,
    lapack_int            ldab,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_cpbcon==NULL) {
        _g_LAPACKE_cpbcon = rindow_load_libopenblas_func("LAPACKE_cpbcon"); 
        if(_g_LAPACKE_cpbcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpbcon(
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
