#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgehrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgehrd)( /* LAPACKE_sgehrd */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* tau */
);
static PFNLAPACKE_sgehrd _g_LAPACKE_sgehrd = NULL;
lapack_int LAPACKE_sgehrd(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    float *            a,
    lapack_int            lda,
    float *            tau
)
{
    if(_g_LAPACKE_sgehrd==NULL) {
        _g_LAPACKE_sgehrd = rindow_load_libopenblas_func("LAPACKE_sgehrd"); 
        if(_g_LAPACKE_sgehrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgehrd(
        matrix_layout,
        n,
        ilo,
        ihi,
        a,
        lda,
        tau    
    );
}
