#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtfttr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtfttr)( /* LAPACKE_dtfttr */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const double *            /* arf */,
    double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_dtfttr _g_LAPACKE_dtfttr = NULL;
lapack_int LAPACKE_dtfttr(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const double *            arf,
    double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_dtfttr==NULL) {
        _g_LAPACKE_dtfttr = rindow_load_libopenblas_func("LAPACKE_dtfttr"); 
        if(_g_LAPACKE_dtfttr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtfttr(
        matrix_layout,
        transr,
        uplo,
        n,
        arf,
        a,
        lda    
    );
}
