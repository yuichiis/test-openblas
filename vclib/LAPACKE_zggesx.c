#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zggesx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zggesx)( /* LAPACKE_zggesx */
    int            /* matrix_layout */,
    char            /* jobvsl */,
    char            /* jobvsr */,
    char            /* sort */,
    LAPACK_Z_SELECT2            /* selctg */,
    char            /* sense */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* sdim */,
    lapack_complex_double *            /* alpha */,
    lapack_complex_double *            /* beta */,
    lapack_complex_double *            /* vsl */,
    lapack_int            /* ldvsl */,
    lapack_complex_double *            /* vsr */,
    lapack_int            /* ldvsr */,
    double *            /* rconde */,
    double *            /* rcondv */
);
static PFNLAPACKE_zggesx _g_LAPACKE_zggesx = NULL;
lapack_int LAPACKE_zggesx(
    int            matrix_layout,
    char            jobvsl,
    char            jobvsr,
    char            sort,
    LAPACK_Z_SELECT2            selctg,
    char            sense,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_int *            sdim,
    lapack_complex_double *            alpha,
    lapack_complex_double *            beta,
    lapack_complex_double *            vsl,
    lapack_int            ldvsl,
    lapack_complex_double *            vsr,
    lapack_int            ldvsr,
    double *            rconde,
    double *            rcondv
)
{
    if(_g_LAPACKE_zggesx==NULL) {
        _g_LAPACKE_zggesx = rindow_load_libopenblas_func("LAPACKE_zggesx"); 
        if(_g_LAPACKE_zggesx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zggesx(
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
