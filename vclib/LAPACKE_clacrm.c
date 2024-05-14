#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clacrm not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clacrm)( /* LAPACKE_clacrm */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_clacrm _g_LAPACKE_clacrm = NULL;
lapack_int LAPACKE_clacrm(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const float *            b,
    lapack_int            ldb,
    lapack_complex_float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_clacrm==NULL) {
        _g_LAPACKE_clacrm = rindow_load_libopenblas_func("LAPACKE_clacrm"); 
        if(_g_LAPACKE_clacrm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clacrm(
        matrix_layout,
        m,
        n,
        a,
        lda,
        b,
        ldb,
        c,
        ldc    
    );
}
