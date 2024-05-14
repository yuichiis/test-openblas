#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgghrd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgghrd_work)( /* LAPACKE_sgghrd_work */
    int            /* matrix_layout */,
    char            /* compq */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* q */,
    lapack_int            /* ldq */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_sgghrd_work _g_LAPACKE_sgghrd_work = NULL;
lapack_int LAPACKE_sgghrd_work(
    int            matrix_layout,
    char            compq,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            q,
    lapack_int            ldq,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_sgghrd_work==NULL) {
        _g_LAPACKE_sgghrd_work = rindow_load_libopenblas_func("LAPACKE_sgghrd_work"); 
        if(_g_LAPACKE_sgghrd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgghrd_work(
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
