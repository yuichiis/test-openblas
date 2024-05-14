#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_shseqr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_shseqr_work)( /* LAPACKE_shseqr_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    float *            /* h */,
    lapack_int            /* ldh */,
    float *            /* wr */,
    float *            /* wi */,
    float *            /* z */,
    lapack_int            /* ldz */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_shseqr_work _g_LAPACKE_shseqr_work = NULL;
lapack_int LAPACKE_shseqr_work(
    int            matrix_layout,
    char            job,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    float *            h,
    lapack_int            ldh,
    float *            wr,
    float *            wi,
    float *            z,
    lapack_int            ldz,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_shseqr_work==NULL) {
        _g_LAPACKE_shseqr_work = rindow_load_libopenblas_func("LAPACKE_shseqr_work"); 
        if(_g_LAPACKE_shseqr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_shseqr_work(
        matrix_layout,
        job,
        compz,
        n,
        ilo,
        ihi,
        h,
        ldh,
        wr,
        wi,
        z,
        ldz,
        work,
        lwork    
    );
}
