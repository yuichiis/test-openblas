#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_somatcopy not found\n";
typedef void (CALLBACK* PFNcblas_somatcopy)( /* cblas_somatcopy */
    OPENBLAS_CONST enum CBLAS_ORDER            /* CORDER */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* CTRANS */,
    OPENBLAS_CONST blasint            /* crows */,
    OPENBLAS_CONST blasint            /* ccols */,
    OPENBLAS_CONST float            /* calpha */,
    OPENBLAS_CONST float *            /* a */,
    OPENBLAS_CONST blasint            /* clda */,
    float *            /* b */,
    OPENBLAS_CONST blasint            /* cldb */
);
static PFNcblas_somatcopy _g_cblas_somatcopy = NULL;
void cblas_somatcopy(
    OPENBLAS_CONST enum CBLAS_ORDER            CORDER,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            CTRANS,
    OPENBLAS_CONST blasint            crows,
    OPENBLAS_CONST blasint            ccols,
    OPENBLAS_CONST float            calpha,
    OPENBLAS_CONST float *            a,
    OPENBLAS_CONST blasint            clda,
    float *            b,
    OPENBLAS_CONST blasint            cldb
)
{
    if(_g_cblas_somatcopy==NULL) {
        _g_cblas_somatcopy = rindow_load_libopenblas_func("cblas_somatcopy"); 
        if(_g_cblas_somatcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_somatcopy(
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
