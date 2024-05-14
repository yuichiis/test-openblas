#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpoequb_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpoequb_work)( /* LAPACKE_dpoequb_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* s */,
    double *            /* scond */,
    double *            /* amax */
);
static PFNLAPACKE_dpoequb_work _g_LAPACKE_dpoequb_work = NULL;
lapack_int LAPACKE_dpoequb_work(
    int            matrix_layout,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double *            s,
    double *            scond,
    double *            amax
)
{
    if(_g_LAPACKE_dpoequb_work==NULL) {
        _g_LAPACKE_dpoequb_work = rindow_load_libopenblas_func("LAPACKE_dpoequb_work"); 
        if(_g_LAPACKE_dpoequb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpoequb_work(
        matrix_layout,
        n,
        a,
        lda,
        s,
        scond,
        amax    
    );
}
