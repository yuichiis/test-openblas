#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgeesx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgeesx)( /* LAPACKE_dgeesx */
    int            /* matrix_layout */,
    char            /* jobvs */,
    char            /* sort */,
    LAPACK_D_SELECT2            /* select */,
    char            /* sense */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* sdim */,
    double *            /* wr */,
    double *            /* wi */,
    double *            /* vs */,
    lapack_int            /* ldvs */,
    double *            /* rconde */,
    double *            /* rcondv */
);
static PFNLAPACKE_dgeesx _g_LAPACKE_dgeesx = NULL;
lapack_int LAPACKE_dgeesx(
    int            matrix_layout,
    char            jobvs,
    char            sort,
    LAPACK_D_SELECT2            select,
    char            sense,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    lapack_int *            sdim,
    double *            wr,
    double *            wi,
    double *            vs,
    lapack_int            ldvs,
    double *            rconde,
    double *            rcondv
)
{
    if(_g_LAPACKE_dgeesx==NULL) {
        _g_LAPACKE_dgeesx = rindow_load_libopenblas_func("LAPACKE_dgeesx"); 
        if(_g_LAPACKE_dgeesx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgeesx(
        matrix_layout,
        jobvs,
        sort,
        select,
        sense,
        n,
        a,
        lda,
        sdim,
        wr,
        wi,
        vs,
        ldvs,
        rconde,
        rcondv    
    );
}
