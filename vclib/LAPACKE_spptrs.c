#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spptrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spptrs)( /* LAPACKE_spptrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* ap */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_spptrs _g_LAPACKE_spptrs = NULL;
lapack_int LAPACKE_spptrs(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            ap,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_spptrs==NULL) {
        _g_LAPACKE_spptrs = rindow_load_libopenblas_func("LAPACKE_spptrs"); 
        if(_g_LAPACKE_spptrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spptrs(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        b,
        ldb    
    );
}
