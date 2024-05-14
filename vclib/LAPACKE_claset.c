#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_claset not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_claset)( /* LAPACKE_claset */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float            /* alpha */,
    lapack_complex_float            /* beta */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_claset _g_LAPACKE_claset = NULL;
lapack_int LAPACKE_claset(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float            alpha,
    lapack_complex_float            beta,
    lapack_complex_float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_claset==NULL) {
        _g_LAPACKE_claset = rindow_load_libopenblas_func("LAPACKE_claset"); 
        if(_g_LAPACKE_claset==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_claset(
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
