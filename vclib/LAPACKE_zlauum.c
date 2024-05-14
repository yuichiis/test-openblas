#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlauum not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlauum)( /* LAPACKE_zlauum */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_zlauum _g_LAPACKE_zlauum = NULL;
lapack_int LAPACKE_zlauum(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_zlauum==NULL) {
        _g_LAPACKE_zlauum = rindow_load_libopenblas_func("LAPACKE_zlauum"); 
        if(_g_LAPACKE_zlauum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlauum(
        matrix_layout,
        uplo,
        n,
        a,
        lda    
    );
}
