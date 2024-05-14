#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cimatcopy not found\n";
typedef void (CALLBACK* PFNcblas_cimatcopy)( /* cblas_cimatcopy */
    OPENBLAS_CONST enum CBLAS_ORDER            /* CORDER */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* CTRANS */,
    OPENBLAS_CONST blasint            /* crows */,
    OPENBLAS_CONST blasint            /* ccols */,
    OPENBLAS_CONST float *            /* calpha */,
    float *            /* a */,
    OPENBLAS_CONST blasint            /* clda */,
    OPENBLAS_CONST blasint            /* cldb */
);
static PFNcblas_cimatcopy _g_cblas_cimatcopy = NULL;
void cblas_cimatcopy(
    OPENBLAS_CONST enum CBLAS_ORDER            CORDER,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            CTRANS,
    OPENBLAS_CONST blasint            crows,
    OPENBLAS_CONST blasint            ccols,
    OPENBLAS_CONST float *            calpha,
    float *            a,
    OPENBLAS_CONST blasint            clda,
    OPENBLAS_CONST blasint            cldb
)
{
    if(_g_cblas_cimatcopy==NULL) {
        _g_cblas_cimatcopy = rindow_load_libopenblas_func("cblas_cimatcopy"); 
        if(_g_cblas_cimatcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cimatcopy(
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
