#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "openblas_get_config not found\n";
typedef char* (CALLBACK* PFNopenblas_get_config)( /* openblas_get_config */
    void            /*  */
);
static PFNopenblas_get_config _g_openblas_get_config = NULL;
char* openblas_get_config(
    void            
)
{
    if(_g_openblas_get_config==NULL) {
        _g_openblas_get_config = rindow_load_libopenblas_func("openblas_get_config"); 
        if(_g_openblas_get_config==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_openblas_get_config(
    
    );
}
