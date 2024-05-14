#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spptri not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spptri)( /* LAPACKE_spptri */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */
);
static PFNLAPACKE_spptri _g_LAPACKE_spptri = NULL;
lapack_int LAPACKE_spptri(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            ap
)
{
    if(_g_LAPACKE_spptri==NULL) {
        _g_LAPACKE_spptri = rindow_load_libopenblas_func("LAPACKE_spptri"); 
        if(_g_LAPACKE_spptri==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spptri(
        matrix_layout,
        uplo,
        n,
        ap    
    );
}
