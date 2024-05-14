#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgbcon not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgbcon)( /* LAPACKE_dgbcon */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const double *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */
);
static PFNLAPACKE_dgbcon _g_LAPACKE_dgbcon = NULL;
lapack_int LAPACKE_dgbcon(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const double *            ab,
    lapack_int            ldab,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond
)
{
    if(_g_LAPACKE_dgbcon==NULL) {
        _g_LAPACKE_dgbcon = rindow_load_libopenblas_func("LAPACKE_dgbcon"); 
        if(_g_LAPACKE_dgbcon==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgbcon(
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
