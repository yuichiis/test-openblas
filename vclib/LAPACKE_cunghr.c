#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cunghr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cunghr)( /* LAPACKE_cunghr */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* tau */
);
static PFNLAPACKE_cunghr _g_LAPACKE_cunghr = NULL;
lapack_int LAPACKE_cunghr(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            tau
)
{
    if(_g_LAPACKE_cunghr==NULL) {
        _g_LAPACKE_cunghr = rindow_load_libopenblas_func("LAPACKE_cunghr"); 
        if(_g_LAPACKE_cunghr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cunghr(
        matrix_layout,
        n,
        ilo,
        ihi,
        a,
        lda,
        tau    
    );
}
