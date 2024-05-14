#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlaset not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlaset)( /* LAPACKE_dlaset */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double            /* alpha */,
    double            /* beta */,
    double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_dlaset _g_LAPACKE_dlaset = NULL;
lapack_int LAPACKE_dlaset(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    double            alpha,
    double            beta,
    double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_dlaset==NULL) {
        _g_LAPACKE_dlaset = rindow_load_libopenblas_func("LAPACKE_dlaset"); 
        if(_g_LAPACKE_dlaset==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlaset(
        matrix_layout,
        uplo,
        m,
        n,
        alpha,
        beta,
        a,
        lda    
    );
}
