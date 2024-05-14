#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeesx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeesx)( /* LAPACKE_sgeesx */
    int            /* matrix_layout */,
    char            /* jobvs */,
    char            /* sort */,
    LAPACK_S_SELECT2            /* select */,
    char            /* sense */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* sdim */,
    float *            /* wr */,
    float *            /* wi */,
    float *            /* vs */,
    lapack_int            /* ldvs */,
    float *            /* rconde */,
    float *            /* rcondv */
);
static PFNLAPACKE_sgeesx _g_LAPACKE_sgeesx = NULL;
lapack_int LAPACKE_sgeesx(
    int            matrix_layout,
    char            jobvs,
    char            sort,
    LAPACK_S_SELECT2            select,
    char            sense,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    lapack_int *            sdim,
    float *            wr,
    float *            wi,
    float *            vs,
    lapack_int            ldvs,
    float *            rconde,
    float *            rcondv
)
{
    if(_g_LAPACKE_sgeesx==NULL) {
        _g_LAPACKE_sgeesx = rindow_load_libopenblas_func("LAPACKE_sgeesx"); 
        if(_g_LAPACKE_sgeesx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeesx(
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
