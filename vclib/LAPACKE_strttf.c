#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strttf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strttf)( /* LAPACKE_strttf */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    float *            /* arf */
);
static PFNLAPACKE_strttf _g_LAPACKE_strttf = NULL;
lapack_int LAPACKE_strttf(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    float *            arf
)
{
    if(_g_LAPACKE_strttf==NULL) {
        _g_LAPACKE_strttf = rindow_load_libopenblas_func("LAPACKE_strttf"); 
        if(_g_LAPACKE_strttf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strttf(
        matrix_layout,
        transr,
        uplo,
        n,
        a,
        lda,
        arf    
    );
}
