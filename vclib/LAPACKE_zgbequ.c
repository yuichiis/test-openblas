#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgbequ not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgbequ)( /* LAPACKE_zgbequ */
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
static PFNLAPACKE_zgbequ _g_LAPACKE_zgbequ = NULL;
lapack_int LAPACKE_zgbequ(
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
    if(_g_LAPACKE_zgbequ==NULL) {
        _g_LAPACKE_zgbequ = rindow_load_libopenblas_func("LAPACKE_zgbequ"); 
        if(_g_LAPACKE_zgbequ==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgbequ(
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
