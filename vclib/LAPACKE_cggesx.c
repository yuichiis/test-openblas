#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggesx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggesx)( /* LAPACKE_cggesx */
    int            /* matrix_layout */,
    char            /* jobvsl */,
    char            /* jobvsr */,
    char            /* sort */,
    LAPACK_C_SELECT2            /* selctg */,
    char            /* sense */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* sdim */,
    lapack_complex_float *            /* alpha */,
    lapack_complex_float *            /* beta */,
    lapack_complex_float *            /* vsl */,
    lapack_int            /* ldvsl */,
    lapack_complex_float *            /* vsr */,
    lapack_int            /* ldvsr */,
    float *            /* rconde */,
    float *            /* rcondv */
);
static PFNLAPACKE_cggesx _g_LAPACKE_cggesx = NULL;
lapack_int LAPACKE_cggesx(
    int            matrix_layout,
    char            jobvsl,
    char            jobvsr,
    char            sort,
    LAPACK_C_SELECT2            selctg,
    char            sense,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_int *            sdim,
    lapack_complex_float *            alpha,
    lapack_complex_float *            beta,
    lapack_complex_float *            vsl,
    lapack_int            ldvsl,
    lapack_complex_float *            vsr,
    lapack_int            ldvsr,
    float *            rconde,
    float *            rcondv
)
{
    if(_g_LAPACKE_cggesx==NULL) {
        _g_LAPACKE_cggesx = rindow_load_libopenblas_func("LAPACKE_cggesx"); 
        if(_g_LAPACKE_cggesx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggesx(
        matrix_layout,
        jobvsl,
        jobvsr,
        sort,
        selctg,
        sense,
        n,
        a,
        lda,
        b,
        ldb,
        sdim,
        alpha,
        beta,
        vsl,
        ldvsl,
        vsr,
        ldvsr,
        rconde,
        rcondv    
    );
}
