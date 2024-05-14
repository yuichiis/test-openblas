#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dorbdb_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dorbdb_work)( /* LAPACKE_dorbdb_work */
    int            /* matrix_layout */,
    char            /* trans */,
    char            /* signs */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* q */,
    double *            /* x11 */,
    lapack_int            /* ldx11 */,
    double *            /* x12 */,
    lapack_int            /* ldx12 */,
    double *            /* x21 */,
    lapack_int            /* ldx21 */,
    double *            /* x22 */,
    lapack_int            /* ldx22 */,
    double *            /* theta */,
    double *            /* phi */,
    double *            /* taup1 */,
    double *            /* taup2 */,
    double *            /* tauq1 */,
    double *            /* tauq2 */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dorbdb_work _g_LAPACKE_dorbdb_work = NULL;
lapack_int LAPACKE_dorbdb_work(
    int            matrix_layout,
    char            trans,
    char            signs,
    lapack_int            m,
    lapack_int            p,
    lapack_int            q,
    double *            x11,
    lapack_int            ldx11,
    double *            x12,
    lapack_int            ldx12,
    double *            x21,
    lapack_int            ldx21,
    double *            x22,
    lapack_int            ldx22,
    double *            theta,
    double *            phi,
    double *            taup1,
    double *            taup2,
    double *            tauq1,
    double *            tauq2,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dorbdb_work==NULL) {
        _g_LAPACKE_dorbdb_work = rindow_load_libopenblas_func("LAPACKE_dorbdb_work"); 
        if(_g_LAPACKE_dorbdb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dorbdb_work(
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
