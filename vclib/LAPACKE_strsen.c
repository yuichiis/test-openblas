#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strsen not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strsen)( /* LAPACKE_strsen */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compq */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    float *            /* t */,
    lapack_int            /* ldt */,
    float *            /* q */,
    lapack_int            /* ldq */,
    float *            /* wr */,
    float *            /* wi */,
    lapack_int *            /* m */,
    float *            /* s */,
    float *            /* sep */
);
static PFNLAPACKE_strsen _g_LAPACKE_strsen = NULL;
lapack_int LAPACKE_strsen(
    int            matrix_layout,
    char            job,
    char            compq,
    const lapack_logical *            select,
    lapack_int            n,
    float *            t,
    lapack_int            ldt,
    float *            q,
    lapack_int            ldq,
    float *            wr,
    float *            wi,
    lapack_int *            m,
    float *            s,
    float *            sep
)
{
    if(_g_LAPACKE_strsen==NULL) {
        _g_LAPACKE_strsen = rindow_load_libopenblas_func("LAPACKE_strsen"); 
        if(_g_LAPACKE_strsen==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strsen(
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
