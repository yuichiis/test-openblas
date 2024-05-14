#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_domatcopy not found\n";
typedef void (CALLBACK* PFNcblas_domatcopy)( /* cblas_domatcopy */
    OPENBLAS_CONST enum CBLAS_ORDER            /* CORDER */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* CTRANS */,
    OPENBLAS_CONST blasint            /* crows */,
    OPENBLAS_CONST blasint            /* ccols */,
    OPENBLAS_CONST double            /* calpha */,
    OPENBLAS_CONST double *            /* a */,
    OPENBLAS_CONST blasint            /* clda */,
    double *            /* b */,
    OPENBLAS_CONST blasint            /* cldb */
);
static PFNcblas_domatcopy _g_cblas_domatcopy = NULL;
void cblas_domatcopy(
    OPENBLAS_CONST enum CBLAS_ORDER            CORDER,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            CTRANS,
    OPENBLAS_CONST blasint            crows,
    OPENBLAS_CONST blasint            ccols,
    OPENBLAS_CONST double            calpha,
    OPENBLAS_CONST double *            a,
    OPENBLAS_CONST blasint            clda,
    double *            b,
    OPENBLAS_CONST blasint            cldb
)
{
    if(_g_cblas_domatcopy==NULL) {
        _g_cblas_domatcopy = rindow_load_libopenblas_func("cblas_domatcopy"); 
        if(_g_cblas_domatcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_domatcopy(
        CORDER,
        CTRANS,
        crows,
        ccols,
        calpha,
        a,
        clda,
        b,
        cldb    
    );
}
