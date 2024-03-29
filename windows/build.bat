SET OPENBLASPATH=C:\OpenBLAS\OpenBLAS-0.3.20-x64
cl -I%OPENBLASPATH%\include /MD loadlib.c openblas_client.c
rem cl -I%OPENBLASPATH%\include %OPENBLASPATH%\lib\libopenblas.lib /MD bit2.c
