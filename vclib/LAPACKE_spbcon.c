#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spbcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spbcon)( /* LAPACKE_spbcon */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const float *            /* ab */,
    lapack_int            /* ldab */,
    float            /* anorm */,
    float *            /* rcond */
);
static PFNLAPACKE_spbcon _g_LAPACKE_spbcon = NULL;
lapack_int LAPACKE_spbcon(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    const float *            ab,
    lapack_int            ldab,
    float            anorm,
    float *            rcond
)
{
    if(_g_LAPACKE_spbcon==NULL) {
        _g_LAPACKE_spbcon = rindow_load_libopenblas_func("LAPACKE_spbcon"); 
        if(_g_LAPACKE_spbcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spbcon(
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
