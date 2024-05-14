#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgees not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgees)( /* LAPACKE_dgees */
    int            /* matrix_layout */,
    char            /* jobvs */,
    char            /* sort */,
    LAPACK_D_SELECT2            /* select */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* sdim */,
    double *            /* wr */,
    double *            /* wi */,
    double *            /* vs */,
    lapack_int            /* ldvs */
);
static PFNLAPACKE_dgees _g_LAPACKE_dgees = NULL;
lapack_int LAPACKE_dgees(
    int            matrix_layout,
    char            jobvs,
    char            sort,
    LAPACK_D_SELECT2            select,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    lapack_int *            sdim,
    double *            wr,
    double *            wi,
    double *            vs,
    lapack_int            ldvs
)
{
    if(_g_LAPACKE_dgees==NULL) {
        _g_LAPACKE_dgees = rindow_load_libopenblas_func("LAPACKE_dgees"); 
        if(_g_LAPACKE_dgees==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgees(
        matrix_layout,
        jobvs,
        sort,
        select,
        n,
        a,
        lda,
        sdim,
        wr,
        wi,
        vs,
        ldvs    
    );
}
