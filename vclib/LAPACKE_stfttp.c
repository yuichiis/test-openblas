#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stfttp not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stfttp)( /* LAPACKE_stfttp */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* arf */,
    float *            /* ap */
);
static PFNLAPACKE_stfttp _g_LAPACKE_stfttp = NULL;
lapack_int LAPACKE_stfttp(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const float *            arf,
    float *            ap
)
{
    if(_g_LAPACKE_stfttp==NULL) {
        _g_LAPACKE_stfttp = rindow_load_libopenblas_func("LAPACKE_stfttp"); 
        if(_g_LAPACKE_stfttp==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stfttp(
        matrix_layout,
        transr,
        uplo,
        n,
        arf,
        ap    
    );
}
