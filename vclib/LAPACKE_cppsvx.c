#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cppsvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cppsvx)( /* LAPACKE_cppsvx */
    int            /* matrix_layout */,
    char            /* fact */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    lapack_complex_float *            /* ap */,
    lapack_complex_float *            /* afp */,
    char *            /* equed */,
    float *            /* s */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* rcond */,
    float *            /* ferr */,
    float *            /* berr */
);
static PFNLAPACKE_cppsvx _g_LAPACKE_cppsvx = NULL;
lapack_int LAPACKE_cppsvx(
    int            matrix_layout,
    char            fact,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    lapack_complex_float *            ap,
    lapack_complex_float *            afp,
    char *            equed,
    float *            s,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            x,
    lapack_int            ldx,
    float *            rcond,
    float *            ferr,
    float *            berr
)
{
    if(_g_LAPACKE_cppsvx==NULL) {
        _g_LAPACKE_cppsvx = rindow_load_libopenblas_func("LAPACKE_cppsvx"); 
        if(_g_LAPACKE_cppsvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cppsvx(
        matrix_layout,
        fact,
        uplo,
        n,
        nrhs,
        ap,
        afp,
        equed,
        s,
        b,
        ldb,
        x,
        ldx,
        rcond,
        ferr,
        berr    
    );
}
