multmatrix.exe 
IF NOT ERRORLEVEL 1 GOTO err

multmatrix.exe matrix.txt
IF ERRORLEVEL 1 GOTO err

multmatrix.exe 123.txt
IF NOT ERRORLEVEL 1 GOTO err

multmatrix.exe matrix.txt output.txt
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
PAUSE
EXIT
:err
ECHO Program testing failed :-(
PAUSE
EXIT

