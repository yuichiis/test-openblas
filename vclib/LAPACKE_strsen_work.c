#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strsen_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strsen_work)( /* LAPACKE_strsen_work */
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
    float *            /* sep */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_strsen_work _g_LAPACKE_strsen_work = NULL;
lapack_int LAPACKE_strsen_work(
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
    float *            sep,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_strsen_work==NULL) {
        _g_LAPACKE_strsen_work = rindow_load_libopenblas_func("LAPACKE_strsen_work"); 
        if(_g_LAPACKE_strsen_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strsen_work(
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
        sep,
        work,
        lwork,
        iwork,
        liwork    
    );
}
