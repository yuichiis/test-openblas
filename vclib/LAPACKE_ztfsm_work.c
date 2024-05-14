#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztfsm_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztfsm_work)( /* LAPACKE_ztfsm_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double            /* alpha */,
    const lapack_complex_double *            /* a */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_ztfsm_work _g_LAPACKE_ztfsm_work = NULL;
lapack_int LAPACKE_ztfsm_work(
    int            matrix_layout,
    char            transr,
    char            side,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double            alpha,
    const lapack_complex_double *            a,
    lapack_complex_double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_ztfsm_work==NULL) {
        _g_LAPACKE_ztfsm_work = rindow_load_libopenblas_func("LAPACKE_ztfsm_work"); 
        if(_g_LAPACKE_ztfsm_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztfsm_work(
        matrix_layout,
        transr,
        side,
        uplo,
        trans,
        diag,
        m,
        n,
        alpha,
        a,
        b,
        ldb    
    );
}
