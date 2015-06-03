vector.exe 
IF NOT ERRORLEVEL 1 GOTO err

vector.exe 4 8 2
IF ERRORLEVEL 1 GOTO err

vector.exe 3.6 12.7 34.7 3.1
IF ERRORLEVEL 1 GOTO err

vector.exe asdfdsf sdfgsdfg dfg
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
PAUSE
EXIT
:err
ECHO Program testing failed :-(
PAUSE
EXIT

