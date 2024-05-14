#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgbequb not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgbequb)( /* LAPACKE_dgbequb */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* r */,
    double *            /* c */,
    double *            /* rowcnd */,
    double *            /* colcnd */,
    double *            /* amax */
);
static PFNLAPACKE_dgbequb _g_LAPACKE_dgbequb = NULL;
lapack_int LAPACKE_dgbequb(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const double *            ab,
    lapack_int            ldab,
    double *            r,
    double *            c,
    double *            rowcnd,
    double *            colcnd,
    double *            amax
)
{
    if(_g_LAPACKE_dgbequb==NULL) {
        _g_LAPACKE_dgbequb = rindow_load_libopenblas_func("LAPACKE_dgbequb"); 
        if(_g_LAPACKE_dgbequb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgbequb(
        matrix_layout,
        m,
        n,
        kl,
        ku,
        ab,
        ldab,
        r,
        c,
        rowcnd,
        colcnd,
        amax    
    );
}
