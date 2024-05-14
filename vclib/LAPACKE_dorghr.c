#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dorghr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dorghr)( /* LAPACKE_dorghr */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */
);
static PFNLAPACKE_dorghr _g_LAPACKE_dorghr = NULL;
lapack_int LAPACKE_dorghr(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    double *            a,
    lapack_int            lda,
    const double *            tau
)
{
    if(_g_LAPACKE_dorghr==NULL) {
        _g_LAPACKE_dorghr = rindow_load_libopenblas_func("LAPACKE_dorghr"); 
        if(_g_LAPACKE_dorghr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dorghr(
        matrix_layout,
        n,
        ilo,
        ihi,
        a,
        lda,
        tau    
    );
}
