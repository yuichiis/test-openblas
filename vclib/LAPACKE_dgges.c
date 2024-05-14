#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgges not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgges)( /* LAPACKE_dgges */
    int            /* matrix_layout */,
    char            /* jobvsl */,
    char            /* jobvsr */,
    char            /* sort */,
    LAPACK_D_SELECT3            /* selctg */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* sdim */,
    double *            /* alphar */,
    double *            /* alphai */,
    double *            /* beta */,
    double *            /* vsl */,
    lapack_int            /* ldvsl */,
    double *            /* vsr */,
    lapack_int            /* ldvsr */
);
static PFNLAPACKE_dgges _g_LAPACKE_dgges = NULL;
lapack_int LAPACKE_dgges(
    int            matrix_layout,
    char            jobvsl,
    char            jobvsr,
    char            sort,
    LAPACK_D_SELECT3            selctg,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    lapack_int *            sdim,
    double *            alphar,
    double *            alphai,
    double *            beta,
    double *            vsl,
    lapack_int            ldvsl,
    double *            vsr,
    lapack_int            ldvsr
)
{
    if(_g_LAPACKE_dgges==NULL) {
        _g_LAPACKE_dgges = rindow_load_libopenblas_func("LAPACKE_dgges"); 
        if(_g_LAPACKE_dgges==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgges(
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
