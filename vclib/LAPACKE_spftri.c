#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spftri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spftri)( /* LAPACKE_spftri */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */
);
static PFNLAPACKE_spftri _g_LAPACKE_spftri = NULL;
lapack_int LAPACKE_spftri(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    float *            a
)
{
    if(_g_LAPACKE_spftri==NULL) {
        _g_LAPACKE_spftri = rindow_load_libopenblas_func("LAPACKE_spftri"); 
        if(_g_LAPACKE_spftri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spftri(
        matrix_layout,
        transr,
        uplo,
        n,
        a    
    );
}
