#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgbequb not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgbequb)( /* LAPACKE_sgbequb */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* r */,
    float *            /* c */,
    float *            /* rowcnd */,
    float *            /* colcnd */,
    float *            /* amax */
);
static PFNLAPACKE_sgbequb _g_LAPACKE_sgbequb = NULL;
lapack_int LAPACKE_sgbequb(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const float *            ab,
    lapack_int            ldab,
    float *            r,
    float *            c,
    float *            rowcnd,
    float *            colcnd,
    float *            amax
)
{
    if(_g_LAPACKE_sgbequb==NULL) {
        _g_LAPACKE_sgbequb = rindow_load_libopenblas_func("LAPACKE_sgbequb"); 
        if(_g_LAPACKE_sgbequb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgbequb(
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
