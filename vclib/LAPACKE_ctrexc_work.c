#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctrexc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctrexc_work)( /* LAPACKE_ctrexc_work */
    int            /* matrix_layout */,
    char            /* compq */,
    lapack_int            /* n */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_int            /* ifst */,
    lapack_int            /* ilst */
);
static PFNLAPACKE_ctrexc_work _g_LAPACKE_ctrexc_work = NULL;
lapack_int LAPACKE_ctrexc_work(
    int            matrix_layout,
    char            compq,
    lapack_int            n,
    lapack_complex_float *            t,
    lapack_int            ldt,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_int            ifst,
    lapack_int            ilst
)
{
    if(_g_LAPACKE_ctrexc_work==NULL) {
        _g_LAPACKE_ctrexc_work = rindow_load_libopenblas_func("LAPACKE_ctrexc_work"); 
        if(_g_LAPACKE_ctrexc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctrexc_work(
        matrix_layout,
        compq,
        n,
        t,
        ldt,
        q,
        ldq,
        ifst,
        ilst    
    );
}
