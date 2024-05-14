#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctgexc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctgexc)( /* LAPACKE_ctgexc */
    int            /* matrix_layout */,
    lapack_logical            /* wantq */,
    lapack_logical            /* wantz */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int            /* ifst */,
    lapack_int            /* ilst */
);
static PFNLAPACKE_ctgexc _g_LAPACKE_ctgexc = NULL;
lapack_int LAPACKE_ctgexc(
    int            matrix_layout,
    lapack_logical            wantq,
    lapack_logical            wantz,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_complex_float *            z,
    lapack_int            ldz,
    lapack_int            ifst,
    lapack_int            ilst
)
{
    if(_g_LAPACKE_ctgexc==NULL) {
        _g_LAPACKE_ctgexc = rindow_load_libopenblas_func("LAPACKE_ctgexc"); 
        if(_g_LAPACKE_ctgexc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctgexc(
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
