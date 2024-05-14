#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztrsyl not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztrsyl)( /* LAPACKE_ztrsyl */
    int            /* matrix_layout */,
    char            /* trana */,
    char            /* tranb */,
    lapack_int            /* isgn */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */,
    double *            /* scale */
);
static PFNLAPACKE_ztrsyl _g_LAPACKE_ztrsyl = NULL;
lapack_int LAPACKE_ztrsyl(
    int            matrix_layout,
    char            trana,
    char            tranb,
    lapack_int            isgn,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            c,
    lapack_int            ldc,
    double *            scale
)
{
    if(_g_LAPACKE_ztrsyl==NULL) {
        _g_LAPACKE_ztrsyl = rindow_load_libopenblas_func("LAPACKE_ztrsyl"); 
        if(_g_LAPACKE_ztrsyl==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztrsyl(
        matrix_layout,
        trana,
        tranb,
        isgn,
        m,
        n,
        a,
        lda,
        b,
        ldb,
        c,
        ldc,
        scale    
    );
}
