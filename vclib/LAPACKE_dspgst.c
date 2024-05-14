#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dspgst not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dspgst)( /* LAPACKE_dspgst */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    const double *            /* bp */
);
static PFNLAPACKE_dspgst _g_LAPACKE_dspgst = NULL;
lapack_int LAPACKE_dspgst(
    int            matrix_layout,
    lapack_int            itype,
    char            uplo,
    lapack_int            n,
    double *            ap,
    const double *            bp
)
{
    if(_g_LAPACKE_dspgst==NULL) {
        _g_LAPACKE_dspgst = rindow_load_libopenblas_func("LAPACKE_dspgst"); 
        if(_g_LAPACKE_dspgst==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dspgst(
        matrix_layout,
        itype,
        uplo,
        n,
        ap,
        bp    
    );
}
