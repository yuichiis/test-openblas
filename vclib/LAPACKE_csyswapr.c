#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_csyswapr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_csyswapr)( /* LAPACKE_csyswapr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int            /* i1 */,
    lapack_int            /* i2 */
);
static PFNLAPACKE_csyswapr _g_LAPACKE_csyswapr = NULL;
lapack_int LAPACKE_csyswapr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int            i1,
    lapack_int            i2
)
{
    if(_g_LAPACKE_csyswapr==NULL) {
        _g_LAPACKE_csyswapr = rindow_load_libopenblas_func("LAPACKE_csyswapr"); 
        if(_g_LAPACKE_csyswapr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_csyswapr(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        i1,
        i2    
    );
}
