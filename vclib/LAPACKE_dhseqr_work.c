#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dhseqr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dhseqr_work)( /* LAPACKE_dhseqr_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    double *            /* h */,
    lapack_int            /* ldh */,
    double *            /* wr */,
    double *            /* wi */,
    double *            /* z */,
    lapack_int            /* ldz */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dhseqr_work _g_LAPACKE_dhseqr_work = NULL;
lapack_int LAPACKE_dhseqr_work(
    int            matrix_layout,
    char            job,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    double *            h,
    lapack_int            ldh,
    double *            wr,
    double *            wi,
    double *            z,
    lapack_int            ldz,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dhseqr_work==NULL) {
        _g_LAPACKE_dhseqr_work = rindow_load_libopenblas_func("LAPACKE_dhseqr_work"); 
        if(_g_LAPACKE_dhseqr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dhseqr_work(
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
