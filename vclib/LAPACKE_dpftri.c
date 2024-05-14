#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpftri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpftri)( /* LAPACKE_dpftri */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */
);
static PFNLAPACKE_dpftri _g_LAPACKE_dpftri = NULL;
lapack_int LAPACKE_dpftri(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    double *            a
)
{
    if(_g_LAPACKE_dpftri==NULL) {
        _g_LAPACKE_dpftri = rindow_load_libopenblas_func("LAPACKE_dpftri"); 
        if(_g_LAPACKE_dpftri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpftri(
        matrix_layout,
        transr,
        uplo,
        n,
        a    
    );
}
