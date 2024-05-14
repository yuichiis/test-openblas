#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctrsen not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctrsen)( /* LAPACKE_ctrsen */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compq */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_float *            /* w */,
    lapack_int *            /* m */,
    float *            /* s */,
    float *            /* sep */
);
static PFNLAPACKE_ctrsen _g_LAPACKE_ctrsen = NULL;
lapack_int LAPACKE_ctrsen(
    int            matrix_layout,
    char            job,
    char            compq,
    const lapack_logical *            select,
    lapack_int            n,
    lapack_complex_float *            t,
    lapack_int            ldt,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_complex_float *            w,
    lapack_int *            m,
    float *            s,
    float *            sep
)
{
    if(_g_LAPACKE_ctrsen==NULL) {
        _g_LAPACKE_ctrsen = rindow_load_libopenblas_func("LAPACKE_ctrsen"); 
        if(_g_LAPACKE_ctrsen==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctrsen(
        matrix_layout,
        job,
        compq,
        select,
        n,
        t,
        ldt,
        q,
        ldq,
        w,
        m,
        s,
        sep    
    );
}
