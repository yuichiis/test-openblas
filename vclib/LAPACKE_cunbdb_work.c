#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cunbdb_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cunbdb_work)( /* LAPACKE_cunbdb_work */
    int            /* matrix_layout */,
    char            /* trans */,
    char            /* signs */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* q */,
    lapack_complex_float *            /* x11 */,
    lapack_int            /* ldx11 */,
    lapack_complex_float *            /* x12 */,
    lapack_int            /* ldx12 */,
    lapack_complex_float *            /* x21 */,
    lapack_int            /* ldx21 */,
    lapack_complex_float *            /* x22 */,
    lapack_int            /* ldx22 */,
    float *            /* theta */,
    float *            /* phi */,
    lapack_complex_float *            /* taup1 */,
    lapack_complex_float *            /* taup2 */,
    lapack_complex_float *            /* tauq1 */,
    lapack_complex_float *            /* tauq2 */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_cunbdb_work _g_LAPACKE_cunbdb_work = NULL;
lapack_int LAPACKE_cunbdb_work(
    int            matrix_layout,
    char            trans,
    char            signs,
    lapack_int            m,
    lapack_int            p,
    lapack_int            q,
    lapack_complex_float *            x11,
    lapack_int            ldx11,
    lapack_complex_float *            x12,
    lapack_int            ldx12,
    lapack_complex_float *            x21,
    lapack_int            ldx21,
    lapack_complex_float *            x22,
    lapack_int            ldx22,
    float *            theta,
    float *            phi,
    lapack_complex_float *            taup1,
    lapack_complex_float *            taup2,
    lapack_complex_float *            tauq1,
    lapack_complex_float *            tauq2,
    lapack_complex_float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_cunbdb_work==NULL) {
        _g_LAPACKE_cunbdb_work = rindow_load_libopenblas_func("LAPACKE_cunbdb_work"); 
        if(_g_LAPACKE_cunbdb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cunbdb_work(
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
