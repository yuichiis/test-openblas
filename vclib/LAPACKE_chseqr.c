#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chseqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chseqr)( /* LAPACKE_chseqr */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    lapack_complex_float *            /* h */,
    lapack_int            /* ldh */,
    lapack_complex_float *            /* w */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_chseqr _g_LAPACKE_chseqr = NULL;
lapack_int LAPACKE_chseqr(
    int            matrix_layout,
    char            job,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    lapack_complex_float *            h,
    lapack_int            ldh,
    lapack_complex_float *            w,
    lapack_complex_float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_chseqr==NULL) {
        _g_LAPACKE_chseqr = rindow_load_libopenblas_func("LAPACKE_chseqr"); 
        if(_g_LAPACKE_chseqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chseqr(
        matrix_layout,
        job,
        compz,
        n,
        ilo,
        ihi,
        h,
        ldh,
        w,
        z,
        ldz    
    );
}
