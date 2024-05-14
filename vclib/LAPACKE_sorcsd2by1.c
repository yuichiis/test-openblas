#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorcsd2by1 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorcsd2by1)( /* LAPACKE_sorcsd2by1 */
    int            /* matrix_layout */,
    char            /* jobu1 */,
    char            /* jobu2 */,
    char            /* jobv1t */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* q */,
    float *            /* x11 */,
    lapack_int            /* ldx11 */,
    float *            /* x21 */,
    lapack_int            /* ldx21 */,
    float *            /* theta */,
    float *            /* u1 */,
    lapack_int            /* ldu1 */,
    float *            /* u2 */,
    lapack_int            /* ldu2 */,
    float *            /* v1t */,
    lapack_int            /* ldv1t */
);
static PFNLAPACKE_sorcsd2by1 _g_LAPACKE_sorcsd2by1 = NULL;
lapack_int LAPACKE_sorcsd2by1(
    int            matrix_layout,
    char            jobu1,
    char            jobu2,
    char            jobv1t,
    lapack_int            m,
    lapack_int            p,
    lapack_int            q,
    float *            x11,
    lapack_int            ldx11,
    float *            x21,
    lapack_int            ldx21,
    float *            theta,
    float *            u1,
    lapack_int            ldu1,
    float *            u2,
    lapack_int            ldu2,
    float *            v1t,
    lapack_int            ldv1t
)
{
    if(_g_LAPACKE_sorcsd2by1==NULL) {
        _g_LAPACKE_sorcsd2by1 = rindow_load_libopenblas_func("LAPACKE_sorcsd2by1"); 
        if(_g_LAPACKE_sorcsd2by1==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorcsd2by1(
        matrix_layout,
        jobu1,
        jobu2,
        jobv1t,
        m,
        p,
        q,
        x11,
        ldx11,
        x21,
        ldx21,
        theta,
        u1,
        ldu1,
        u2,
        ldu2,
        v1t,
        ldv1t    
    );
}
