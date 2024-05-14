#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chseqr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chseqr_work)( /* LAPACKE_chseqr_work */
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
    lapack_int            /* ldz */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_chseqr_work _g_LAPACKE_chseqr_work = NULL;
lapack_int LAPACKE_chseqr_work(
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
    lapack_int            ldz,
    lapack_complex_float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_chseqr_work==NULL) {
        _g_LAPACKE_chseqr_work = rindow_load_libopenblas_func("LAPACKE_chseqr_work"); 
        if(_g_LAPACKE_chseqr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chseqr_work(
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
        ldz,
        work,
        lwork    
    );
}
