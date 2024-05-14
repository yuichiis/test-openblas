#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztfttp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztfttp)( /* LAPACKE_ztfttp */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* arf */,
    lapack_complex_double *            /* ap */
);
static PFNLAPACKE_ztfttp _g_LAPACKE_ztfttp = NULL;
lapack_int LAPACKE_ztfttp(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            arf,
    lapack_complex_double *            ap
)
{
    if(_g_LAPACKE_ztfttp==NULL) {
        _g_LAPACKE_ztfttp = rindow_load_libopenblas_func("LAPACKE_ztfttp"); 
        if(_g_LAPACKE_ztfttp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztfttp(
        matrix_layout,
        transr,
        uplo,
        n,
        arf,
        ap    
    );
}
