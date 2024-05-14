#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dstedc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dstedc_work)( /* LAPACKE_dstedc_work */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    double *            /* z */,
    lapack_int            /* ldz */,
    double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_dstedc_work _g_LAPACKE_dstedc_work = NULL;
lapack_int LAPACKE_dstedc_work(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    double *            d,
    double *            e,
    double *            z,
    lapack_int            ldz,
    double *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_dstedc_work==NULL) {
        _g_LAPACKE_dstedc_work = rindow_load_libopenblas_func("LAPACKE_dstedc_work"); 
        if(_g_LAPACKE_dstedc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dstedc_work(
        matrix_layout,
        compz,
        n,
        d,
        e,
        z,
        ldz,
        work,
        lwork,
        iwork,
        liwork    
    );
}
