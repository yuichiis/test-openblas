#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgghd3 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgghd3)( /* LAPACKE_dgghd3 */
    int            /* matrix_layout */,
    char            /* compq */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* q */,
    lapack_int            /* ldq */,
    double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_dgghd3 _g_LAPACKE_dgghd3 = NULL;
lapack_int LAPACKE_dgghd3(
    int            matrix_layout,
    char            compq,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            q,
    lapack_int            ldq,
    double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_dgghd3==NULL) {
        _g_LAPACKE_dgghd3 = rindow_load_libopenblas_func("LAPACKE_dgghd3"); 
        if(_g_LAPACKE_dgghd3==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgghd3(
        matrix_layout,
        compq,
        compz,
        n,
        ilo,
        ihi,
        a,
        lda,
        b,
        ldb,
        q,
        ldq,
        z,
        ldz    
    );
}
