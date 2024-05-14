#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zuncsd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zuncsd)( /* LAPACKE_zuncsd */
    int            /* matrix_layout */,
    char            /* jobu1 */,
    char            /* jobu2 */,
    char            /* jobv1t */,
    char            /* jobv2t */,
    char            /* trans */,
    char            /* signs */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* q */,
    lapack_complex_double *            /* x11 */,
    lapack_int            /* ldx11 */,
    lapack_complex_double *            /* x12 */,
    lapack_int            /* ldx12 */,
    lapack_complex_double *            /* x21 */,
    lapack_int            /* ldx21 */,
    lapack_complex_double *            /* x22 */,
    lapack_int            /* ldx22 */,
    double *            /* theta */,
    lapack_complex_double *            /* u1 */,
    lapack_int            /* ldu1 */,
    lapack_complex_double *            /* u2 */,
    lapack_int            /* ldu2 */,
    lapack_complex_double *            /* v1t */,
    lapack_int            /* ldv1t */,
    lapack_complex_double *            /* v2t */,
    lapack_int            /* ldv2t */
);
static PFNLAPACKE_zuncsd _g_LAPACKE_zuncsd = NULL;
lapack_int LAPACKE_zuncsd(
    int            matrix_layout,
    char            jobu1,
    char            jobu2,
    char            jobv1t,
    char            jobv2t,
    char            trans,
    char            signs,
    lapack_int            m,
    lapack_int            p,
    lapack_int            q,
    lapack_complex_double *            x11,
    lapack_int            ldx11,
    lapack_complex_double *            x12,
    lapack_int            ldx12,
    lapack_complex_double *            x21,
    lapack_int            ldx21,
    lapack_complex_double *            x22,
    lapack_int            ldx22,
    double *            theta,
    lapack_complex_double *            u1,
    lapack_int            ldu1,
    lapack_complex_double *            u2,
    lapack_int            ldu2,
    lapack_complex_double *            v1t,
    lapack_int            ldv1t,
    lapack_complex_double *            v2t,
    lapack_int            ldv2t
)
{
    if(_g_LAPACKE_zuncsd==NULL) {
        _g_LAPACKE_zuncsd = rindow_load_libopenblas_func("LAPACKE_zuncsd"); 
        if(_g_LAPACKE_zuncsd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zuncsd(
        matrix_layout,
        jobu1,
        jobu2,
        jobv1t,
        jobv2t,
        trans,
        signs,
        m,
        p,
        q,
        x11,
        ldx11,
        x12,
        ldx12,
        x21,
        ldx21,
        x22,
        ldx22,
        theta,
        u1,
        ldu1,
        u2,
        ldu2,
        v1t,
        ldv1t,
        v2t,
        ldv2t    
    );
}
