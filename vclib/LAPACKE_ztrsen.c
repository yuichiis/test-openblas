#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztrsen not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztrsen)( /* LAPACKE_ztrsen */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compq */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    lapack_complex_double *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_double *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_double *            /* w */,
    lapack_int *            /* m */,
    double *            /* s */,
    double *            /* sep */
);
static PFNLAPACKE_ztrsen _g_LAPACKE_ztrsen = NULL;
lapack_int LAPACKE_ztrsen(
    int            matrix_layout,
    char            job,
    char            compq,
    const lapack_logical *            select,
    lapack_int            n,
    lapack_complex_double *            t,
    lapack_int            ldt,
    lapack_complex_double *            q,
    lapack_int            ldq,
    lapack_complex_double *            w,
    lapack_int *            m,
    double *            s,
    double *            sep
)
{
    if(_g_LAPACKE_ztrsen==NULL) {
        _g_LAPACKE_ztrsen = rindow_load_libopenblas_func("LAPACKE_ztrsen"); 
        if(_g_LAPACKE_ztrsen==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztrsen(
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
