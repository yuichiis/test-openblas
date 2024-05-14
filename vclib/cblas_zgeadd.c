#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zgeadd not found\n";
typedef void (CALLBACK* PFNcblas_zgeadd)( /* cblas_zgeadd */
    OPENBLAS_CONST enum CBLAS_ORDER            /* CORDER */,
    OPENBLAS_CONST blasint            /* crows */,
    OPENBLAS_CONST blasint            /* ccols */,
    OPENBLAS_CONST double *            /* calpha */,
    double *            /* a */,
    OPENBLAS_CONST blasint            /* clda */,
    OPENBLAS_CONST double *            /* cbeta */,
    double *            /* c */,
    OPENBLAS_CONST blasint            /* cldc */
);
static PFNcblas_zgeadd _g_cblas_zgeadd = NULL;
void cblas_zgeadd(
    OPENBLAS_CONST enum CBLAS_ORDER            CORDER,
    OPENBLAS_CONST blasint            crows,
    OPENBLAS_CONST blasint            ccols,
    OPENBLAS_CONST double *            calpha,
    double *            a,
    OPENBLAS_CONST blasint            clda,
    OPENBLAS_CONST double *            cbeta,
    double *            c,
    OPENBLAS_CONST blasint            cldc
)
{
    if(_g_cblas_zgeadd==NULL) {
        _g_cblas_zgeadd = rindow_load_libopenblas_func("cblas_zgeadd"); 
        if(_g_cblas_zgeadd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zgeadd(
        CORDER,
        crows,
        ccols,
        calpha,
        a,
        clda,
        cbeta,
        c,
        cldc    
    );
}
