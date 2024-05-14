#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dbdsdc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dbdsdc_work)( /* LAPACKE_dbdsdc_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* compq */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    double *            /* u */,
    lapack_int            /* ldu */,
    double *            /* vt */,
    lapack_int            /* ldvt */,
    double *            /* q */,
    lapack_int *            /* iq */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dbdsdc_work _g_LAPACKE_dbdsdc_work = NULL;
lapack_int LAPACKE_dbdsdc_work(
    int            matrix_layout,
    char            uplo,
    char            compq,
    lapack_int            n,
    double *            d,
    double *            e,
    double *            u,
    lapack_int            ldu,
    double *            vt,
    lapack_int            ldvt,
    double *            q,
    lapack_int *            iq,
    double *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dbdsdc_work==NULL) {
        _g_LAPACKE_dbdsdc_work = rindow_load_libopenblas_func("LAPACKE_dbdsdc_work"); 
        if(_g_LAPACKE_dbdsdc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dbdsdc_work(
        matrix_layout,
        uplo,
        compq,
        n,
        d,
        e,
        u,
        ldu,
        vt,
        ldvt,
        q,
        iq,
        work,
        iwork    
    );
}
