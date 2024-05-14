#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgelsy not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgelsy)( /* LAPACKE_zgelsy */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* jpvt */,
    double            /* rcond */,
    lapack_int *            /* rank */
);
static PFNLAPACKE_zgelsy _g_LAPACKE_zgelsy = NULL;
lapack_int LAPACKE_zgelsy(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_int *            jpvt,
    double            rcond,
    lapack_int *            rank
)
{
    if(_g_LAPACKE_zgelsy==NULL) {
        _g_LAPACKE_zgelsy = rindow_load_libopenblas_func("LAPACKE_zgelsy"); 
        if(_g_LAPACKE_zgelsy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgelsy(
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
