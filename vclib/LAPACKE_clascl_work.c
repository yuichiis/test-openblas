#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clascl_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clascl_work)( /* LAPACKE_clascl_work */
    int            /* matrix_layout */,
    char            /* type */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    float            /* cfrom */,
    float            /* cto */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_clascl_work _g_LAPACKE_clascl_work = NULL;
lapack_int LAPACKE_clascl_work(
    int            matrix_layout,
    char            type,
    lapack_int            kl,
    lapack_int            ku,
    float            cfrom,
    float            cto,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_clascl_work==NULL) {
        _g_LAPACKE_clascl_work = rindow_load_libopenblas_func("LAPACKE_clascl_work"); 
        if(_g_LAPACKE_clascl_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clascl_work(
        matrix_layout,
        type,
        kl,
        ku,
        cfrom,
        cto,
        m,
        n,
        a,
        lda    
    );
}
