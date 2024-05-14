#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtrsen not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtrsen)( /* LAPACKE_dtrsen */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compq */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    double *            /* t */,
    lapack_int            /* ldt */,
    double *            /* q */,
    lapack_int            /* ldq */,
    double *            /* wr */,
    double *            /* wi */,
    lapack_int *            /* m */,
    double *            /* s */,
    double *            /* sep */
);
static PFNLAPACKE_dtrsen _g_LAPACKE_dtrsen = NULL;
lapack_int LAPACKE_dtrsen(
    int            matrix_layout,
    char            job,
    char            compq,
    const lapack_logical *            select,
    lapack_int            n,
    double *            t,
    lapack_int            ldt,
    double *            q,
    lapack_int            ldq,
    double *            wr,
    double *            wi,
    lapack_int *            m,
    double *            s,
    double *            sep
)
{
    if(_g_LAPACKE_dtrsen==NULL) {
        _g_LAPACKE_dtrsen = rindow_load_libopenblas_func("LAPACKE_dtrsen"); 
        if(_g_LAPACKE_dtrsen==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtrsen(
        matrix_layout,
        job,
        compq,
        select,
        n,
        t,
        ldt,
        q,
        ldq,
        wr,
        wi,
        m,
        s,
        sep    
    );
}
