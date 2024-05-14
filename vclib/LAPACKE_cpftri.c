#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpftri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpftri)( /* LAPACKE_cpftri */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */
);
static PFNLAPACKE_cpftri _g_LAPACKE_cpftri = NULL;
lapack_int LAPACKE_cpftri(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a
)
{
    if(_g_LAPACKE_cpftri==NULL) {
        _g_LAPACKE_cpftri = rindow_load_libopenblas_func("LAPACKE_cpftri"); 
        if(_g_LAPACKE_cpftri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpftri(
        matrix_layout,
        transr,
        uplo,
        n,
        a    
    );
}
