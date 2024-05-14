#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strexc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strexc_work)( /* LAPACKE_strexc_work */
    int            /* matrix_layout */,
    char            /* compq */,
    lapack_int            /* n */,
    float *            /* t */,
    lapack_int            /* ldt */,
    float *            /* q */,
    lapack_int            /* ldq */,
    lapack_int *            /* ifst */,
    lapack_int *            /* ilst */,
    float *            /* work */
);
static PFNLAPACKE_strexc_work _g_LAPACKE_strexc_work = NULL;
lapack_int LAPACKE_strexc_work(
    int            matrix_layout,
    char            compq,
    lapack_int            n,
    float *            t,
    lapack_int            ldt,
    float *            q,
    lapack_int            ldq,
    lapack_int *            ifst,
    lapack_int *            ilst,
    float *            work
)
{
    if(_g_LAPACKE_strexc_work==NULL) {
        _g_LAPACKE_strexc_work = rindow_load_libopenblas_func("LAPACKE_strexc_work"); 
        if(_g_LAPACKE_strexc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strexc_work(
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
