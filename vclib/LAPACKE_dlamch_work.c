#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlamch_work not found\n";
typedef double (CALLBACK* PFNLAPACKE_dlamch_work)( /* LAPACKE_dlamch_work */
    char            /* cmach */
);
static PFNLAPACKE_dlamch_work _g_LAPACKE_dlamch_work = NULL;
double LAPACKE_dlamch_work(
    char            cmach
)
{
    if(_g_LAPACKE_dlamch_work==NULL) {
        _g_LAPACKE_dlamch_work = rindow_load_libopenblas_func("LAPACKE_dlamch_work"); 
        if(_g_LAPACKE_dlamch_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlamch_work(
        cmach    
    );
}
