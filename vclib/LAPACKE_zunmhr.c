#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zunmhr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zunmhr)( /* LAPACKE_zunmhr */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_zunmhr _g_LAPACKE_zunmhr = NULL;
lapack_int LAPACKE_zunmhr(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            tau,
    lapack_complex_double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_zunmhr==NULL) {
        _g_LAPACKE_zunmhr = rindow_load_libopenblas_func("LAPACKE_zunmhr"); 
        if(_g_LAPACKE_zunmhr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zunmhr(
        matrix_layout,
        side,
        trans,
        m,
        n,
        ilo,
        ihi,
        a,
        lda,
        tau,
        c,
        ldc    
    );
}
