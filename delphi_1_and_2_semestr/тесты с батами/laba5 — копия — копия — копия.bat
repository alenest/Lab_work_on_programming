@echo off


for /l %%x in (1, 1, 6) do (
   	start "" "C:\Users\user\Desktop\laba5\Win32\Debug\laba5.exe" "C:\Users\user\Desktop\laba5\Test and Answer\test%%x.txt" "C:\Users\user\Desktop\laba5\Test and Answer\answer.txt" 

       :LOOP
      tasklist | find /i "laba5" >nul 2>&1
      IF ERRORLEVEL 1 (
      goto ebattya
     ) ELSE (
     ECHO laba5 is still running
      Timeout /T 5 /Nobreak
      GOTO LOOP
      )
 
     ebattya


)




"C:\Users\user\Desktop\laba5\Test and Answer\answer.txt"



