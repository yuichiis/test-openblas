#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zunghr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zunghr)( /* LAPACKE_zunghr */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zunghr _g_LAPACKE_zunghr = NULL;
lapack_int LAPACKE_zunghr(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zunghr==NULL) {
        _g_LAPACKE_zunghr = rindow_load_libopenblas_func("LAPACKE_zunghr"); 
        if(_g_LAPACKE_zunghr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zunghr(
        matrix_layout,
        n,
        ilo,
        ihi,
        a,
        lda,
        tau    
    );
}
