#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctfttp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctfttp)( /* LAPACKE_ctfttp */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* arf */,
    lapack_complex_float *            /* ap */
);
static PFNLAPACKE_ctfttp _g_LAPACKE_ctfttp = NULL;
lapack_int LAPACKE_ctfttp(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            arf,
    lapack_complex_float *            ap
)
{
    if(_g_LAPACKE_ctfttp==NULL) {
        _g_LAPACKE_ctfttp = rindow_load_libopenblas_func("LAPACKE_ctfttp"); 
        if(_g_LAPACKE_ctfttp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctfttp(
        matrix_layout,
        transr,
        uplo,
        n,
        arf,
        ap    
    );
}
