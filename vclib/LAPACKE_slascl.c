#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slascl not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slascl)( /* LAPACKE_slascl */
    int            /* matrix_layout */,
    char            /* type */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    float            /* cfrom */,
    float            /* cto */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_slascl _g_LAPACKE_slascl = NULL;
lapack_int LAPACKE_slascl(
    int            matrix_layout,
    char            type,
    lapack_int            kl,
    lapack_int            ku,
    float            cfrom,
    float            cto,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_slascl==NULL) {
        _g_LAPACKE_slascl = rindow_load_libopenblas_func("LAPACKE_slascl"); 
        if(_g_LAPACKE_slascl==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slascl(
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
