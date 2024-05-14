#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sspgst not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sspgst)( /* LAPACKE_sspgst */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */,
    const float *            /* bp */
);
static PFNLAPACKE_sspgst _g_LAPACKE_sspgst = NULL;
lapack_int LAPACKE_sspgst(
    int            matrix_layout,
    lapack_int            itype,
    char            uplo,
    lapack_int            n,
    float *            ap,
    const float *            bp
)
{
    if(_g_LAPACKE_sspgst==NULL) {
        _g_LAPACKE_sspgst = rindow_load_libopenblas_func("LAPACKE_sspgst"); 
        if(_g_LAPACKE_sspgst==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sspgst(
        matrix_layout,
        itype,
        uplo,
        n,
        ap,
        bp    
    );
}
