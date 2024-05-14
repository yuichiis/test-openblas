#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strsyl not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strsyl)( /* LAPACKE_strsyl */
    int            /* matrix_layout */,
    char            /* trana */,
    char            /* tranb */,
    lapack_int            /* isgn */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* scale */
);
static PFNLAPACKE_strsyl _g_LAPACKE_strsyl = NULL;
lapack_int LAPACKE_strsyl(
    int            matrix_layout,
    char            trana,
    char            tranb,
    lapack_int            isgn,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    const float *            b,
    lapack_int            ldb,
    float *            c,
    lapack_int            ldc,
    float *            scale
)
{
    if(_g_LAPACKE_strsyl==NULL) {
        _g_LAPACKE_strsyl = rindow_load_libopenblas_func("LAPACKE_strsyl"); 
        if(_g_LAPACKE_strsyl==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strsyl(
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
