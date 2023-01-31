@rem cl -I..\OpenBLAS-0.3.7-x64\include ..\OpenBLAS-0.3.7-x64\lib\libopenblas.lib /MD bit2.c
@SET TMPLIB=%LIB%
@SET LIB=C:\OpenBLAS\miniconda3\Library\lib;%LIB%
@rem cl -IC:\OpenBLAS\OpenBLAS-0.3.7-vc15-x64-static\include C:\OpenBLAS\OpenBLAS-0.3.7-vc15-x64-static\lib\openblas.lib /MD tst_dgesvd.c
@rem cl -IC:\OpenBLAS\OpenBLAS-0.3.10-x64\include C:\OpenBLAS\OpenBLAS-0.3.10-x64\lib\libopenblas.lib /MD tst_dgesvd.c
cl -IC:\OpenBLAS\OpenBLAS-0.3.13-x64\include C:\OpenBLAS\OpenBLAS-0.3.13-x64\lib\libopenblas.lib /MD tst_dgesvd.c
@SET LIB=%TMPLIB%
@SET TMPLIB=
