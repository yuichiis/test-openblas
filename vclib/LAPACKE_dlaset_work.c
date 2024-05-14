#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlaset_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlaset_work)( /* LAPACKE_dlaset_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double            /* alpha */,
    double            /* beta */,
    double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_dlaset_work _g_LAPACKE_dlaset_work = NULL;
lapack_int LAPACKE_dlaset_work(
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
    if(_g_LAPACKE_dlaset_work==NULL) {
        _g_LAPACKE_dlaset_work = rindow_load_libopenblas_func("LAPACKE_dlaset_work"); 
        if(_g_LAPACKE_dlaset_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlaset_work(
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
