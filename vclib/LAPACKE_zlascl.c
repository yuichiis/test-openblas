#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlascl not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlascl)( /* LAPACKE_zlascl */
    int            /* matrix_layout */,
    char            /* type */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    double            /* cfrom */,
    double            /* cto */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_zlascl _g_LAPACKE_zlascl = NULL;
lapack_int LAPACKE_zlascl(
    int            matrix_layout,
    char            type,
    lapack_int            kl,
    lapack_int            ku,
    double            cfrom,
    double            cto,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_zlascl==NULL) {
        _g_LAPACKE_zlascl = rindow_load_libopenblas_func("LAPACKE_zlascl"); 
        if(_g_LAPACKE_zlascl==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlascl(
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
