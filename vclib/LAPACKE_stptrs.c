#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stptrs not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stptrs)( /* LAPACKE_stptrs */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* trans */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* ap */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_stptrs _g_LAPACKE_stptrs = NULL;
lapack_int LAPACKE_stptrs(
    int            matrix_layout,
    char            uplo,
    char            trans,
    char            diag,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            ap,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_stptrs==NULL) {
        _g_LAPACKE_stptrs = rindow_load_libopenblas_func("LAPACKE_stptrs"); 
        if(_g_LAPACKE_stptrs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stptrs(
        matrix_layout,
        uplo,
        trans,
        diag,
        n,
        nrhs,
        ap,
        b,
        ldb    
    );
}
