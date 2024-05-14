#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dgeadd not found\n";
typedef void (CALLBACK* PFNcblas_dgeadd)( /* cblas_dgeadd */
    OPENBLAS_CONST enum CBLAS_ORDER            /* CORDER */,
    OPENBLAS_CONST blasint            /* crows */,
    OPENBLAS_CONST blasint            /* ccols */,
    OPENBLAS_CONST double            /* calpha */,
    double *            /* a */,
    OPENBLAS_CONST blasint            /* clda */,
    OPENBLAS_CONST double            /* cbeta */,
    double *            /* c */,
    OPENBLAS_CONST blasint            /* cldc */
);
static PFNcblas_dgeadd _g_cblas_dgeadd = NULL;
void cblas_dgeadd(
    OPENBLAS_CONST enum CBLAS_ORDER            CORDER,
    OPENBLAS_CONST blasint            crows,
    OPENBLAS_CONST blasint            ccols,
    OPENBLAS_CONST double            calpha,
    double *            a,
    OPENBLAS_CONST blasint            clda,
    OPENBLAS_CONST double            cbeta,
    double *            c,
    OPENBLAS_CONST blasint            cldc
)
{
    if(_g_cblas_dgeadd==NULL) {
        _g_cblas_dgeadd = rindow_load_libopenblas_func("cblas_dgeadd"); 
        if(_g_cblas_dgeadd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dgeadd(
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
