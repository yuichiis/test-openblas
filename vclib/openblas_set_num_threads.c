#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "openblas_set_num_threads not found\n";
typedef void (CALLBACK* PFNopenblas_set_num_threads)( /* openblas_set_num_threads */
    int            /* num_threads */
);
static PFNopenblas_set_num_threads _g_openblas_set_num_threads = NULL;
void openblas_set_num_threads(
    int            num_threads
)
{
    if(_g_openblas_set_num_threads==NULL) {
        _g_openblas_set_num_threads = rindow_load_libopenblas_func("openblas_set_num_threads"); 
        if(_g_openblas_set_num_threads==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_openblas_set_num_threads(
        num_threads    
    );
}
