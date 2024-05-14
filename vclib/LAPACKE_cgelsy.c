#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgelsy not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgelsy)( /* LAPACKE_cgelsy */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* jpvt */,
    float            /* rcond */,
    lapack_int *            /* rank */
);
static PFNLAPACKE_cgelsy _g_LAPACKE_cgelsy = NULL;
lapack_int LAPACKE_cgelsy(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_int *            jpvt,
    float            rcond,
    lapack_int *            rank
)
{
    if(_g_LAPACKE_cgelsy==NULL) {
        _g_LAPACKE_cgelsy = rindow_load_libopenblas_func("LAPACKE_cgelsy"); 
        if(_g_LAPACKE_cgelsy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgelsy(
        matrix_layout,
        m,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb,
        jpvt,
        rcond,
        rank    
    );
}
