#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgbequb not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgbequb)( /* LAPACKE_zgbequb */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* r */,
    double *            /* c */,
    double *            /* rowcnd */,
    double *            /* colcnd */,
    double *            /* amax */
);
static PFNLAPACKE_zgbequb _g_LAPACKE_zgbequb = NULL;
lapack_int LAPACKE_zgbequb(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const lapack_complex_double *            ab,
    lapack_int            ldab,
    double *            r,
    double *            c,
    double *            rowcnd,
    double *            colcnd,
    double *            amax
)
{
    if(_g_LAPACKE_zgbequb==NULL) {
        _g_LAPACKE_zgbequb = rindow_load_libopenblas_func("LAPACKE_zgbequb"); 
        if(_g_LAPACKE_zgbequb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgbequb(
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
