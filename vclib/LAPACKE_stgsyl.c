#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stgsyl not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stgsyl)( /* LAPACKE_stgsyl */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* ijob */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* c */,
    lapack_int            /* ldc */,
    const float *            /* d */,
    lapack_int            /* ldd */,
    const float *            /* e */,
    lapack_int            /* lde */,
    float *            /* f */,
    lapack_int            /* ldf */,
    float *            /* scale */,
    float *            /* dif */
);
static PFNLAPACKE_stgsyl _g_LAPACKE_stgsyl = NULL;
lapack_int LAPACKE_stgsyl(
    int            matrix_layout,
    char            trans,
    lapack_int            ijob,
    lapack_int            m,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    const float *            b,
    lapack_int            ldb,
    float *            c,
    lapack_int            ldc,
    const float *            d,
    lapack_int            ldd,
    const float *            e,
    lapack_int            lde,
    float *            f,
    lapack_int            ldf,
    float *            scale,
    float *            dif
)
{
    if(_g_LAPACKE_stgsyl==NULL) {
        _g_LAPACKE_stgsyl = rindow_load_libopenblas_func("LAPACKE_stgsyl"); 
        if(_g_LAPACKE_stgsyl==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stgsyl(
        matrix_layout,
        trans,
        ijob,
        m,
        n,
        a,
        lda,
        b,
        ldb,
        c,
        ldc,
        d,
        ldd,
        e,
        lde,
        f,
        ldf,
        scale,
        dif    
    );
}
