#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgbtrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgbtrs)( /* LAPACKE_zgbtrs */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    lapack_int            /* nrhs */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_int *            /* ipiv */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_zgbtrs _g_LAPACKE_zgbtrs = NULL;
lapack_int LAPACKE_zgbtrs(
    int            matrix_layout,
    char            trans,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    lapack_int            nrhs,
    const lapack_complex_double *            ab,
    lapack_int            ldab,
    const lapack_int *            ipiv,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_zgbtrs==NULL) {
        _g_LAPACKE_zgbtrs = rindow_load_libopenblas_func("LAPACKE_zgbtrs"); 
        if(_g_LAPACKE_zgbtrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgbtrs(
        matrix_layout,
        trans,
        n,
        kl,
        ku,
        nrhs,
        ab,
        ldab,
        ipiv,
        b,
        ldb    
    );
}
