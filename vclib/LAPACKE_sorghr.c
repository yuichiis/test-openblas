#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorghr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorghr)( /* LAPACKE_sorghr */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */
);
static PFNLAPACKE_sorghr _g_LAPACKE_sorghr = NULL;
lapack_int LAPACKE_sorghr(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    float *            a,
    lapack_int            lda,
    const float *            tau
)
{
    if(_g_LAPACKE_sorghr==NULL) {
        _g_LAPACKE_sorghr = rindow_load_libopenblas_func("LAPACKE_sorghr"); 
        if(_g_LAPACKE_sorghr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorghr(
        matrix_layout,
        n,
        ilo,
        ihi,
        a,
        lda,
        tau    
    );
}
