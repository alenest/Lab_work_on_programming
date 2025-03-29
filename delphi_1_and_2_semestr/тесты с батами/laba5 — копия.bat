@echo off

set COUNTER=1

goto loop 
:loop
if %COUNTER%==6 goto end
start "" "C:\Users\user\Desktop\laba5\Win32\Debug\laba5.exe" "C:\Users\user\Desktop\laba5\Test and Answer\test%COUNTER%.txt" "C:\Users\user\Desktop\laba5\Test and Answer\answer.txt"
set /A COUNTER=COUNTER+1
goto loop

:end
"C:\Users\user\Desktop\laba5\Test and Answer\answer.txt"



