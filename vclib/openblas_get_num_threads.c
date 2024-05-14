#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "openblas_get_num_threads not found\n";
typedef int (CALLBACK* PFNopenblas_get_num_threads)( /* openblas_get_num_threads */
    void            /*  */
);
static PFNopenblas_get_num_threads _g_openblas_get_num_threads = NULL;
int openblas_get_num_threads(
    void            
)
{
    if(_g_openblas_get_num_threads==NULL) {
        _g_openblas_get_num_threads = rindow_load_libopenblas_func("openblas_get_num_threads"); 
        if(_g_openblas_get_num_threads==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_openblas_get_num_threads(
    
    );
}
