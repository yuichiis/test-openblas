#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dimatcopy not found\n";
typedef void (CALLBACK* PFNcblas_dimatcopy)( /* cblas_dimatcopy */
    OPENBLAS_CONST enum CBLAS_ORDER            /* CORDER */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* CTRANS */,
    OPENBLAS_CONST blasint            /* crows */,
    OPENBLAS_CONST blasint            /* ccols */,
    OPENBLAS_CONST double            /* calpha */,
    double *            /* a */,
    OPENBLAS_CONST blasint            /* clda */,
    OPENBLAS_CONST blasint            /* cldb */
);
static PFNcblas_dimatcopy _g_cblas_dimatcopy = NULL;
void cblas_dimatcopy(
    OPENBLAS_CONST enum CBLAS_ORDER            CORDER,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            CTRANS,
    OPENBLAS_CONST blasint            crows,
    OPENBLAS_CONST blasint            ccols,
    OPENBLAS_CONST double            calpha,
    double *            a,
    OPENBLAS_CONST blasint            clda,
    OPENBLAS_CONST blasint            cldb
)
{
    if(_g_cblas_dimatcopy==NULL) {
        _g_cblas_dimatcopy = rindow_load_libopenblas_func("cblas_dimatcopy"); 
        if(_g_cblas_dimatcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dimatcopy(
        CORDER,
        CTRANS,
        crows,
        ccols,
        calpha,
        a,
        clda,
        cldb    
    );
}
