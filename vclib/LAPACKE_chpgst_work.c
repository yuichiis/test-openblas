#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chpgst_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chpgst_work)( /* LAPACKE_chpgst_work */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */,
    const lapack_complex_float *            /* bp */
);
static PFNLAPACKE_chpgst_work _g_LAPACKE_chpgst_work = NULL;
lapack_int LAPACKE_chpgst_work(
    int            matrix_layout,
    lapack_int            itype,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap,
    const lapack_complex_float *            bp
)
{
    if(_g_LAPACKE_chpgst_work==NULL) {
        _g_LAPACKE_chpgst_work = rindow_load_libopenblas_func("LAPACKE_chpgst_work"); 
        if(_g_LAPACKE_chpgst_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chpgst_work(
        matrix_layout,
        itype,
        uplo,
        n,
        ap,
        bp    
    );
}
