#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_comatcopy not found\n";
typedef void (CALLBACK* PFNcblas_comatcopy)( /* cblas_comatcopy */
    OPENBLAS_CONST enum CBLAS_ORDER            /* CORDER */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* CTRANS */,
    OPENBLAS_CONST blasint            /* crows */,
    OPENBLAS_CONST blasint            /* ccols */,
    OPENBLAS_CONST float *            /* calpha */,
    OPENBLAS_CONST float *            /* a */,
    OPENBLAS_CONST blasint            /* clda */,
    float *            /* b */,
    OPENBLAS_CONST blasint            /* cldb */
);
static PFNcblas_comatcopy _g_cblas_comatcopy = NULL;
void cblas_comatcopy(
    OPENBLAS_CONST enum CBLAS_ORDER            CORDER,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            CTRANS,
    OPENBLAS_CONST blasint            crows,
    OPENBLAS_CONST blasint            ccols,
    OPENBLAS_CONST float *            calpha,
    OPENBLAS_CONST float *            a,
    OPENBLAS_CONST blasint            clda,
    float *            b,
    OPENBLAS_CONST blasint            cldb
)
{
    if(_g_cblas_comatcopy==NULL) {
        _g_cblas_comatcopy = rindow_load_libopenblas_func("cblas_comatcopy"); 
        if(_g_cblas_comatcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_comatcopy(
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
