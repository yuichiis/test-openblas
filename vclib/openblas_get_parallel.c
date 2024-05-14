#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "openblas_get_parallel not found\n";
typedef int (CALLBACK* PFNopenblas_get_parallel)( /* openblas_get_parallel */
    void            /*  */
);
static PFNopenblas_get_parallel _g_openblas_get_parallel = NULL;
int openblas_get_parallel(
    void            
)
{
    if(_g_openblas_get_parallel==NULL) {
        _g_openblas_get_parallel = rindow_load_libopenblas_func("openblas_get_parallel"); 
        if(_g_openblas_get_parallel==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_openblas_get_parallel(
    
    );
}
