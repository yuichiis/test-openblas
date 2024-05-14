#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtfttp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtfttp)( /* LAPACKE_dtfttp */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* arf */,
    double *            /* ap */
);
static PFNLAPACKE_dtfttp _g_LAPACKE_dtfttp = NULL;
lapack_int LAPACKE_dtfttp(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const double *            arf,
    double *            ap
)
{
    if(_g_LAPACKE_dtfttp==NULL) {
        _g_LAPACKE_dtfttp = rindow_load_libopenblas_func("LAPACKE_dtfttp"); 
        if(_g_LAPACKE_dtfttp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtfttp(
        matrix_layout,
        transr,
        uplo,
        n,
        arf,
        ap    
    );
}
