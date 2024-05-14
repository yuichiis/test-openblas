#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stfsm not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stfsm)( /* LAPACKE_stfsm */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float            /* alpha */,
    const float *            /* a */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_stfsm _g_LAPACKE_stfsm = NULL;
lapack_int LAPACKE_stfsm(
    int            matrix_layout,
    char            transr,
    char            side,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            m,
    lapack_int            n,
    float            alpha,
    const float *            a,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_stfsm==NULL) {
        _g_LAPACKE_stfsm = rindow_load_libopenblas_func("LAPACKE_stfsm"); 
        if(_g_LAPACKE_stfsm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stfsm(
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
