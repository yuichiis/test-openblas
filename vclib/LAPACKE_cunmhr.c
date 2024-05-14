#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cunmhr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cunmhr)( /* LAPACKE_cunmhr */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* tau */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_cunmhr _g_LAPACKE_cunmhr = NULL;
lapack_int LAPACKE_cunmhr(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            tau,
    lapack_complex_float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_cunmhr==NULL) {
        _g_LAPACKE_cunmhr = rindow_load_libopenblas_func("LAPACKE_cunmhr"); 
        if(_g_LAPACKE_cunmhr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cunmhr(
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
