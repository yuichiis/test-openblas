#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_srotmg not found\n";
typedef void (CALLBACK* PFNcblas_srotmg)( /* cblas_srotmg */
    float *            /* d1 */,
    float *            /* d2 */,
    float *            /* b1 */,
    OPENBLAS_CONST float            /* b2 */,
    float *            /* P */
);
static PFNcblas_srotmg _g_cblas_srotmg = NULL;
void cblas_srotmg(
    float *            d1,
    float *            d2,
    float *            b1,
    OPENBLAS_CONST float            b2,
    float *            P
)
{
    if(_g_cblas_srotmg==NULL) {
        _g_cblas_srotmg = rindow_load_libopenblas_func("cblas_srotmg"); 
        if(_g_cblas_srotmg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_srotmg(
        d1,
        d2,
        b1,
        b2,
        P    
    );
}
