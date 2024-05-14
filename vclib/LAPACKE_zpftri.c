#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpftri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpftri)( /* LAPACKE_zpftri */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */
);
static PFNLAPACKE_zpftri _g_LAPACKE_zpftri = NULL;
lapack_int LAPACKE_zpftri(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a
)
{
    if(_g_LAPACKE_zpftri==NULL) {
        _g_LAPACKE_zpftri = rindow_load_libopenblas_func("LAPACKE_zpftri"); 
        if(_g_LAPACKE_zpftri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpftri(
        matrix_layout,
        transr,
        uplo,
        n,
        a    
    );
}
