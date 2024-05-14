#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cbdsqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cbdsqr)( /* LAPACKE_cbdsqr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ncvt */,
    lapack_int            /* nru */,
    lapack_int            /* ncc */,
    float *            /* d */,
    float *            /* e */,
    lapack_complex_float *            /* vt */,
    lapack_int            /* ldvt */,
    lapack_complex_float *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_cbdsqr _g_LAPACKE_cbdsqr = NULL;
lapack_int LAPACKE_cbdsqr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            ncvt,
    lapack_int            nru,
    lapack_int            ncc,
    float *            d,
    float *            e,
    lapack_complex_float *            vt,
    lapack_int            ldvt,
    lapack_complex_float *            u,
    lapack_int            ldu,
    lapack_complex_float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_cbdsqr==NULL) {
        _g_LAPACKE_cbdsqr = rindow_load_libopenblas_func("LAPACKE_cbdsqr"); 
        if(_g_LAPACKE_cbdsqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cbdsqr(
        matrix_layout,
        uplo,
        n,
        ncvt,
        nru,
        ncc,
        d,
        e,
        vt,
        ldvt,
        u,
        ldu,
        c,
        ldc    
    );
}
