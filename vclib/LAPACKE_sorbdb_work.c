#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorbdb_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorbdb_work)( /* LAPACKE_sorbdb_work */
    int            /* matrix_layout */,
    char            /* trans */,
    char            /* signs */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* q */,
    float *            /* x11 */,
    lapack_int            /* ldx11 */,
    float *            /* x12 */,
    lapack_int            /* ldx12 */,
    float *            /* x21 */,
    lapack_int            /* ldx21 */,
    float *            /* x22 */,
    lapack_int            /* ldx22 */,
    float *            /* theta */,
    float *            /* phi */,
    float *            /* taup1 */,
    float *            /* taup2 */,
    float *            /* tauq1 */,
    float *            /* tauq2 */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sorbdb_work _g_LAPACKE_sorbdb_work = NULL;
lapack_int LAPACKE_sorbdb_work(
    int            matrix_layout,
    char            trans,
    char            signs,
    lapack_int            m,
    lapack_int            p,
    lapack_int            q,
    float *            x11,
    lapack_int            ldx11,
    float *            x12,
    lapack_int            ldx12,
    float *            x21,
    lapack_int            ldx21,
    float *            x22,
    lapack_int            ldx22,
    float *            theta,
    float *            phi,
    float *            taup1,
    float *            taup2,
    float *            tauq1,
    float *            tauq2,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sorbdb_work==NULL) {
        _g_LAPACKE_sorbdb_work = rindow_load_libopenblas_func("LAPACKE_sorbdb_work"); 
        if(_g_LAPACKE_sorbdb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorbdb_work(
        matrix_layout,
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
        phi,
        taup1,
        taup2,
        tauq1,
        tauq2,
        work,
        lwork    
    );
}
