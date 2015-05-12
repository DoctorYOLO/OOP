copyfile.exe
IF NOT ERRORLEVEL 1 GOTO err

copyfile.exe myfile.txt 
IF NOT ERRORLEVEL 1 GOTO err

copyfile.exe myfile.txt myfile(copy).txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
PAUSE
EXIT
:err
ECHO Program testing failed :-(
PAUSE
EXIT

