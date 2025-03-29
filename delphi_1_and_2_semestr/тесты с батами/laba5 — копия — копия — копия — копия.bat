@echo off


for /l %%x in (1, 1, 6) do (
   	start "" "C:\Users\user\Desktop\laba5\Win32\Debug\laba5.exe" "C:\Users\user\Desktop\laba5\Test and Answer\test%%x.txt" "C:\Users\user\Desktop\laba5\Test and Answer\answer.txt" 

       :loop
       timeout /t 1 /nobreak >nul 2>&1
       tasklist | find /i "laba5.exe" >nul 2>&1
       if errorlevel 1 goto cont
       goto loop
       

       
)




"C:\Users\user\Desktop\laba5\Test and Answer\answer.txt"



