#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtgexc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtgexc)( /* LAPACKE_dtgexc */
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
    lapack_int *            /* ilst */
);
static PFNLAPACKE_dtgexc _g_LAPACKE_dtgexc = NULL;
lapack_int LAPACKE_dtgexc(
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
    lapack_int *            ilst
)
{
    if(_g_LAPACKE_dtgexc==NULL) {
        _g_LAPACKE_dtgexc = rindow_load_libopenblas_func("LAPACKE_dtgexc"); 
        if(_g_LAPACKE_dtgexc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtgexc(
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
        ilst    
    );
}
