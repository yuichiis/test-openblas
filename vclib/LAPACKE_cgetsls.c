#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgetsls not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgetsls)( /* LAPACKE_cgetsls */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_cgetsls _g_LAPACKE_cgetsls = NULL;
lapack_int LAPACKE_cgetsls(
    int            matrix_layout,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_cgetsls==NULL) {
        _g_LAPACKE_cgetsls = rindow_load_libopenblas_func("LAPACKE_cgetsls"); 
        if(_g_LAPACKE_cgetsls==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgetsls(
        matrix_layout,
        trans,
        m,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb    
    );
}
