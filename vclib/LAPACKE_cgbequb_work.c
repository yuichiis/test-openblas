#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgbequb_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgbequb_work)( /* LAPACKE_cgbequb_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* r */,
    float *            /* c */,
    float *            /* rowcnd */,
    float *            /* colcnd */,
    float *            /* amax */
);
static PFNLAPACKE_cgbequb_work _g_LAPACKE_cgbequb_work = NULL;
lapack_int LAPACKE_cgbequb_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const lapack_complex_float *            ab,
    lapack_int            ldab,
    float *            r,
    float *            c,
    float *            rowcnd,
    float *            colcnd,
    float *            amax
)
{
    if(_g_LAPACKE_cgbequb_work==NULL) {
        _g_LAPACKE_cgbequb_work = rindow_load_libopenblas_func("LAPACKE_cgbequb_work"); 
        if(_g_LAPACKE_cgbequb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgbequb_work(
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
