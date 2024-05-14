#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sbdsvdx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sbdsvdx)( /* LAPACKE_sbdsvdx */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* jobz */,
    char            /* range */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* ns */,
    float *            /* s */,
    float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* superb */
);
static PFNLAPACKE_sbdsvdx _g_LAPACKE_sbdsvdx = NULL;
lapack_int LAPACKE_sbdsvdx(
    int            matrix_layout,
    char            uplo,
    char            jobz,
    char            range,
    lapack_int            n,
    float *            d,
    float *            e,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            ns,
    float *            s,
    float *            z,
    lapack_int            ldz,
    lapack_int *            superb
)
{
    if(_g_LAPACKE_sbdsvdx==NULL) {
        _g_LAPACKE_sbdsvdx = rindow_load_libopenblas_func("LAPACKE_sbdsvdx"); 
        if(_g_LAPACKE_sbdsvdx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sbdsvdx(
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
