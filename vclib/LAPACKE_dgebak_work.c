#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgebak_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgebak_work)( /* LAPACKE_dgebak_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* side */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    const double *            /* scale */,
    lapack_int            /* m */,
    double *            /* v */,
    lapack_int            /* ldv */
);
static PFNLAPACKE_dgebak_work _g_LAPACKE_dgebak_work = NULL;
lapack_int LAPACKE_dgebak_work(
    int            matrix_layout,
    char            job,
    char            side,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    const double *            scale,
    lapack_int            m,
    double *            v,
    lapack_int            ldv
)
{
    if(_g_LAPACKE_dgebak_work==NULL) {
        _g_LAPACKE_dgebak_work = rindow_load_libopenblas_func("LAPACKE_dgebak_work"); 
        if(_g_LAPACKE_dgebak_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgebak_work(
        matrix_layout,
        job,
        side,
        n,
        ilo,
        ihi,
        scale,
        m,
        v,
        ldv    
    );
}
