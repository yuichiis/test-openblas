#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dbdsdc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dbdsdc)( /* LAPACKE_dbdsdc */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* compq */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    double *            /* u */,
    lapack_int            /* ldu */,
    double *            /* vt */,
    lapack_int            /* ldvt */,
    double *            /* q */,
    lapack_int *            /* iq */
);
static PFNLAPACKE_dbdsdc _g_LAPACKE_dbdsdc = NULL;
lapack_int LAPACKE_dbdsdc(
    int            matrix_layout,
    char            uplo,
    char            compq,
    lapack_int            n,
    double *            d,
    double *            e,
    double *            u,
    lapack_int            ldu,
    double *            vt,
    lapack_int            ldvt,
    double *            q,
    lapack_int *            iq
)
{
    if(_g_LAPACKE_dbdsdc==NULL) {
        _g_LAPACKE_dbdsdc = rindow_load_libopenblas_func("LAPACKE_dbdsdc"); 
        if(_g_LAPACKE_dbdsdc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dbdsdc(
        matrix_layout,
        uplo,
        compq,
        n,
        d,
        e,
        u,
        ldu,
        vt,
        ldvt,
        q,
        iq    
    );
}
