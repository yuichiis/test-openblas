#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssbgst not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssbgst)( /* LAPACKE_ssbgst */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ka */,
    lapack_int            /* kb */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    const float *            /* bb */,
    lapack_int            /* ldbb */,
    float *            /* x */,
    lapack_int            /* ldx */
);
static PFNLAPACKE_ssbgst _g_LAPACKE_ssbgst = NULL;
lapack_int LAPACKE_ssbgst(
    int            matrix_layout,
    char            vect,
    char            uplo,
    lapack_int            n,
    lapack_int            ka,
    lapack_int            kb,
    float *            ab,
    lapack_int            ldab,
    const float *            bb,
    lapack_int            ldbb,
    float *            x,
    lapack_int            ldx
)
{
    if(_g_LAPACKE_ssbgst==NULL) {
        _g_LAPACKE_ssbgst = rindow_load_libopenblas_func("LAPACKE_ssbgst"); 
        if(_g_LAPACKE_ssbgst==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssbgst(
        matrix_layout,
        vect,
        uplo,
        n,
        ka,
        kb,
        ab,
        ldab,
        bb,
        ldbb,
        x,
        ldx    
    );
}
