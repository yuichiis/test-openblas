#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dormhr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dormhr)( /* LAPACKE_dormhr */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* tau */,
    double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_dormhr _g_LAPACKE_dormhr = NULL;
lapack_int LAPACKE_dormhr(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    const double *            a,
    lapack_int            lda,
    const double *            tau,
    double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_dormhr==NULL) {
        _g_LAPACKE_dormhr = rindow_load_libopenblas_func("LAPACKE_dormhr"); 
        if(_g_LAPACKE_dormhr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dormhr(
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
