#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhpgst not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhpgst)( /* LAPACKE_zhpgst */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    const lapack_complex_double *            /* bp */
);
static PFNLAPACKE_zhpgst _g_LAPACKE_zhpgst = NULL;
lapack_int LAPACKE_zhpgst(
    int            matrix_layout,
    lapack_int            itype,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    const lapack_complex_double *            bp
)
{
    if(_g_LAPACKE_zhpgst==NULL) {
        _g_LAPACKE_zhpgst = rindow_load_libopenblas_func("LAPACKE_zhpgst"); 
        if(_g_LAPACKE_zhpgst==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhpgst(
        matrix_layout,
        itype,
        uplo,
        n,
        ap,
        bp    
    );
}
