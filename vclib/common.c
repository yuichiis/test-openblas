#include <Windows.h>
#include <cblas.h>
#include "vclib.h"

static HMODULE _h_libopenblas = NULL;
static char msg_load_error[]  = "Load error: libopenblas\n";
void* rindow_load_libopenblas_func(char *funcname)
{
    if(_h_libopenblas==NULL) {
        _h_libopenblas = LoadLibraryA( "libopenblas.dll" );
        if(_h_libopenblas==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_load_error, sizeof(msg_load_error), NULL, NULL);
            return NULL;
        }
    }
    return GetProcAddress( _h_libopenblas, funcname );
}
