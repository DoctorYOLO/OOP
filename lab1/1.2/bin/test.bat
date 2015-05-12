bin2dec.exe
IF NOT ERRORLEVEL 1 GOTO err

bin2dec.exe 00111100
IF ERRORLEVEL 1 GOTO err

bin2dec.exe 67
IF NOT ERRORLEVEL 1 GOTO err

bin2dec.exe 00101110 45
IF NOT ERRORLEVEL 1 GOTO err

bin2dec.exe sdgsdg
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
PAUSE
EXIT
:err
ECHO Program testing failed :-(
PAUSE
EXIT

