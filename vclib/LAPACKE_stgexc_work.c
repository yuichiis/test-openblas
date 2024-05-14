#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stgexc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stgexc_work)( /* LAPACKE_stgexc_work */
    int            /* matrix_layout */,
    lapack_logical            /* wantq */,
    lapack_logical            /* wantz */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* q */,
    lapack_int            /* ldq */,
    float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifst */,
    lapack_int *            /* ilst */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_stgexc_work _g_LAPACKE_stgexc_work = NULL;
lapack_int LAPACKE_stgexc_work(
    int            matrix_layout,
    lapack_logical            wantq,
    lapack_logical            wantz,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            q,
    lapack_int            ldq,
    float *            z,
    lapack_int            ldz,
    lapack_int *            ifst,
    lapack_int *            ilst,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_stgexc_work==NULL) {
        _g_LAPACKE_stgexc_work = rindow_load_libopenblas_func("LAPACKE_stgexc_work"); 
        if(_g_LAPACKE_stgexc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stgexc_work(
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
