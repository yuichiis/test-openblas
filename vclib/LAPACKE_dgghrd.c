#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgghrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgghrd)( /* LAPACKE_dgghrd */
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
static PFNLAPACKE_dgghrd _g_LAPACKE_dgghrd = NULL;
lapack_int LAPACKE_dgghrd(
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
    if(_g_LAPACKE_dgghrd==NULL) {
        _g_LAPACKE_dgghrd = rindow_load_libopenblas_func("LAPACKE_dgghrd"); 
        if(_g_LAPACKE_dgghrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgghrd(
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
