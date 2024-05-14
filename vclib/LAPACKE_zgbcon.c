#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgbcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgbcon)( /* LAPACKE_zgbcon */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_zgbcon _g_LAPACKE_zgbcon = NULL;
lapack_int LAPACKE_zgbcon(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const lapack_complex_double *            ab,
    lapack_int            ldab,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_zgbcon==NULL) {
        _g_LAPACKE_zgbcon = rindow_load_libopenblas_func("LAPACKE_zgbcon"); 
        if(_g_LAPACKE_zgbcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgbcon(
        matrix_layout,
        norm,
        n,
        kl,
        ku,
        ab,
        ldab,
        ipiv,
        anorm,
        rcond    
    );
}
