#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dbdsvdx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dbdsvdx)( /* LAPACKE_dbdsvdx */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* jobz */,
    char            /* range */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    double            /* vl */,
    double            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* ns */,
    double *            /* s */,
    double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* superb */
);
static PFNLAPACKE_dbdsvdx _g_LAPACKE_dbdsvdx = NULL;
lapack_int LAPACKE_dbdsvdx(
    int            matrix_layout,
    char            uplo,
    char            jobz,
    char            range,
    lapack_int            n,
    double *            d,
    double *            e,
    double            vl,
    double            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            ns,
    double *            s,
    double *            z,
    lapack_int            ldz,
    lapack_int *            superb
)
{
    if(_g_LAPACKE_dbdsvdx==NULL) {
        _g_LAPACKE_dbdsvdx = rindow_load_libopenblas_func("LAPACKE_dbdsvdx"); 
        if(_g_LAPACKE_dbdsvdx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dbdsvdx(
        matrix_layout,
        uplo,
        jobz,
        range,
        n,
        d,
        e,
        vl,
        vu,
        il,
        iu,
        ns,
        s,
        z,
        ldz,
        superb    
    );
}
