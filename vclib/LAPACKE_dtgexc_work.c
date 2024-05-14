#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtgexc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtgexc_work)( /* LAPACKE_dtgexc_work */
    int            /* matrix_layout */,
    lapack_logical            /* wantq */,
    lapack_logical            /* wantz */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* q */,
    lapack_int            /* ldq */,
    double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifst */,
    lapack_int *            /* ilst */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dtgexc_work _g_LAPACKE_dtgexc_work = NULL;
lapack_int LAPACKE_dtgexc_work(
    int            matrix_layout,
    lapack_logical            wantq,
    lapack_logical            wantz,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            q,
    lapack_int            ldq,
    double *            z,
    lapack_int            ldz,
    lapack_int *            ifst,
    lapack_int *            ilst,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dtgexc_work==NULL) {
        _g_LAPACKE_dtgexc_work = rindow_load_libopenblas_func("LAPACKE_dtgexc_work"); 
        if(_g_LAPACKE_dtgexc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtgexc_work(
        matrix_layout,
        wantq,
        wantz,
        n,
        a,
        lda,
        b,
        ldb,
        q,
        ldq,
        z,
        ldz,
        ifst,
        ilst,
        work,
        lwork    
    );
}
