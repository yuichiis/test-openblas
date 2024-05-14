#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtrexc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtrexc_work)( /* LAPACKE_dtrexc_work */
    int            /* matrix_layout */,
    char            /* compq */,
    lapack_int            /* n */,
    double *            /* t */,
    lapack_int            /* ldt */,
    double *            /* q */,
    lapack_int            /* ldq */,
    lapack_int *            /* ifst */,
    lapack_int *            /* ilst */,
    double *            /* work */
);
static PFNLAPACKE_dtrexc_work _g_LAPACKE_dtrexc_work = NULL;
lapack_int LAPACKE_dtrexc_work(
    int            matrix_layout,
    char            compq,
    lapack_int            n,
    double *            t,
    lapack_int            ldt,
    double *            q,
    lapack_int            ldq,
    lapack_int *            ifst,
    lapack_int *            ilst,
    double *            work
)
{
    if(_g_LAPACKE_dtrexc_work==NULL) {
        _g_LAPACKE_dtrexc_work = rindow_load_libopenblas_func("LAPACKE_dtrexc_work"); 
        if(_g_LAPACKE_dtrexc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtrexc_work(
        matrix_layout,
        compq,
        n,
        t,
        ldt,
        q,
        ldq,
        ifst,
        ilst,
        work    
    );
}
