#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgees not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgees)( /* LAPACKE_zgees */
    int            /* matrix_layout */,
    char            /* jobvs */,
    char            /* sort */,
    LAPACK_Z_SELECT1            /* select */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* sdim */,
    lapack_complex_double *            /* w */,
    lapack_complex_double *            /* vs */,
    lapack_int            /* ldvs */
);
static PFNLAPACKE_zgees _g_LAPACKE_zgees = NULL;
lapack_int LAPACKE_zgees(
    int            matrix_layout,
    char            jobvs,
    char            sort,
    LAPACK_Z_SELECT1            select,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_int *            sdim,
    lapack_complex_double *            w,
    lapack_complex_double *            vs,
    lapack_int            ldvs
)
{
    if(_g_LAPACKE_zgees==NULL) {
        _g_LAPACKE_zgees = rindow_load_libopenblas_func("LAPACKE_zgees"); 
        if(_g_LAPACKE_zgees==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgees(
        matrix_layout,
        jobvs,
        sort,
        select,
        n,
        a,
        lda,
        sdim,
        w,
        vs,
        ldvs    
    );
}
