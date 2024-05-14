#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sbbcsd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sbbcsd_work)( /* LAPACKE_sbbcsd_work */
    int            /* matrix_layout */,
    char            /* jobu1 */,
    char            /* jobu2 */,
    char            /* jobv1t */,
    char            /* jobv2t */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* q */,
    float *            /* theta */,
    float *            /* phi */,
    float *            /* u1 */,
    lapack_int            /* ldu1 */,
    float *            /* u2 */,
    lapack_int            /* ldu2 */,
    float *            /* v1t */,
    lapack_int            /* ldv1t */,
    float *            /* v2t */,
    lapack_int            /* ldv2t */,
    float *            /* b11d */,
    float *            /* b11e */,
    float *            /* b12d */,
    float *            /* b12e */,
    float *            /* b21d */,
    float *            /* b21e */,
    float *            /* b22d */,
    float *            /* b22e */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sbbcsd_work _g_LAPACKE_sbbcsd_work = NULL;
lapack_int LAPACKE_sbbcsd_work(
    int            matrix_layout,
    char            jobu1,
    char            jobu2,
    char            jobv1t,
    char            jobv2t,
    char            trans,
    lapack_int            m,
    lapack_int            p,
    lapack_int            q,
    float *            theta,
    float *            phi,
    float *            u1,
    lapack_int            ldu1,
    float *            u2,
    lapack_int            ldu2,
    float *            v1t,
    lapack_int            ldv1t,
    float *            v2t,
    lapack_int            ldv2t,
    float *            b11d,
    float *            b11e,
    float *            b12d,
    float *            b12e,
    float *            b21d,
    float *            b21e,
    float *            b22d,
    float *            b22e,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sbbcsd_work==NULL) {
        _g_LAPACKE_sbbcsd_work = rindow_load_libopenblas_func("LAPACKE_sbbcsd_work"); 
        if(_g_LAPACKE_sbbcsd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sbbcsd_work(
        matrix_layout,
        jobu1,
        jobu2,
        jobv1t,
        jobv2t,
        trans,
        m,
        p,
        q,
        theta,
        phi,
        u1,
        ldu1,
        u2,
        ldu2,
        v1t,
        ldv1t,
        v2t,
        ldv2t,
        b11d,
        b11e,
        b12d,
        b12e,
        b21d,
        b21e,
        b22d,
        b22e,
        work,
        lwork    
    );
}
