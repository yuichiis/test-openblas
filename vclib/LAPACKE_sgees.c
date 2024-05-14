#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgees not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgees)( /* LAPACKE_sgees */
    int            /* matrix_layout */,
    char            /* jobvs */,
    char            /* sort */,
    LAPACK_S_SELECT2            /* select */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* sdim */,
    float *            /* wr */,
    float *            /* wi */,
    float *            /* vs */,
    lapack_int            /* ldvs */
);
static PFNLAPACKE_sgees _g_LAPACKE_sgees = NULL;
lapack_int LAPACKE_sgees(
    int            matrix_layout,
    char            jobvs,
    char            sort,
    LAPACK_S_SELECT2            select,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    lapack_int *            sdim,
    float *            wr,
    float *            wi,
    float *            vs,
    lapack_int            ldvs
)
{
    if(_g_LAPACKE_sgees==NULL) {
        _g_LAPACKE_sgees = rindow_load_libopenblas_func("LAPACKE_sgees"); 
        if(_g_LAPACKE_sgees==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgees(
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
