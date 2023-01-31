@rem cl -I..\OpenBLAS-0.3.7-x64\include ..\OpenBLAS-0.3.7-x64\lib\libopenblas.lib /MD bit2.c
@SET TMPLIB=%LIB%
@SET TMPINCLUDE=%INCLUDE%
@rem SET LIB=C:\OpenBLAS\OpenBLAS-0.3.7-vc15-x64-static\lib;C:\OpenBLAS\miniconda3\Library\lib;%LIB%
@rem SET INCLUDE=C:\OpenBLAS\OpenBLAS-0.3.7-vc15-x64-static\include;%INCLUDE%
@rem SET LIB=C:\OpenBLAS\OpenBLAS-0.3.10-x64\lib;%LIB%
@rem SET INCLUDE=C:\OpenBLAS\OpenBLAS-0.3.10-x64\include;%INCLUDE%
@SET LIB=C:\OpenBLAS\OpenBLAS-0.3.13-x64\lib;%LIB%
@SET INCLUDE=C:\OpenBLAS\OpenBLAS-0.3.13-x64\include;%INCLUDE%
cl libopenblas.lib -W3 /MD tst_edgesvd.c
@SET LIB=%TMPLIB%
@SET INCLUDE=%TMPINCLUDE%
@SET TMPLIB=
@SET TMPINCLUDE=
