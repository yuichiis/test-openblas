#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgges not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgges)( /* LAPACKE_sgges */
    int            /* matrix_layout */,
    char            /* jobvsl */,
    char            /* jobvsr */,
    char            /* sort */,
    LAPACK_S_SELECT3            /* selctg */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* sdim */,
    float *            /* alphar */,
    float *            /* alphai */,
    float *            /* beta */,
    float *            /* vsl */,
    lapack_int            /* ldvsl */,
    float *            /* vsr */,
    lapack_int            /* ldvsr */
);
static PFNLAPACKE_sgges _g_LAPACKE_sgges = NULL;
lapack_int LAPACKE_sgges(
    int            matrix_layout,
    char            jobvsl,
    char            jobvsr,
    char            sort,
    LAPACK_S_SELECT3            selctg,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    lapack_int *            sdim,
    float *            alphar,
    float *            alphai,
    float *            beta,
    float *            vsl,
    lapack_int            ldvsl,
    float *            vsr,
    lapack_int            ldvsr
)
{
    if(_g_LAPACKE_sgges==NULL) {
        _g_LAPACKE_sgges = rindow_load_libopenblas_func("LAPACKE_sgges"); 
        if(_g_LAPACKE_sgges==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgges(
        matrix_layout,
        jobvsl,
        jobvsr,
        sort,
        selctg,
        n,
        a,
        lda,
        b,
        ldb,
        sdim,
        alphar,
        alphai,
        beta,
        vsl,
        ldvsl,
        vsr,
        ldvsr    
    );
}
