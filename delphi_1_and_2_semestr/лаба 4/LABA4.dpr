program LABA4;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  Windows,
  System.SysUtils;

const
  Nmax = 200;
var
  x, y : array[1..Nmax] of real;
  CX, CY, ANSWER : real;
  n, i, nx, ny : integer;
  //F : file;
  dat, res: TextFile;
  //Name := 'a:\MyFiles\MyFile.Dat';
     //C:\Users\user\Desktop\лаба 4\файлы

begin
  //Name := 'a:\MyFiles\MyFile.Dat';
    //AssignFile (f, 'C:\Users\user\Desktop\лаба 4\файлы\Ebal beglyanok.txt');
    //AssignFile(f,'MyFile.Dat');

   assignFile(dat, ParamStr(1));
  //AssignFile (dat, 'C:\Users\user\Desktop\лаба 4\файлы\test1.txt');
  Reset (dat);

    //C:\Users\user\Desktop\лаба 4\файлы\test1.txt C:\Users\user\Desktop\лаба 4\файлы\answer.txt
   assignFile(res, ParamStr(2));
  //AssignFile (res, 'C:\Users\user\Desktop\лаба 4\файлы\answer.txt');
  Rewrite (res);



  setConsoleCP(1251); // для ввода русификация и
  setConsoleOutputCP(1251);
  //write(dat, 'Количество элементов в вещественных массивах X и Y: ');
  read(dat, n);

  if (n < 1) or (n > Nmax) then writeln(res, 'Недопустимое значение для n')
    else
  begin
    //writeln(res, 'Введите ', n, ' элемент(ов) массива X ');
    for i:= 1 to n do read(dat, x[i]);
    //writeln(res, 'Введите ', n, ' элемент(ов) массива Y ');
    for i:= 1 to n do read(dat, y[i]);


    //readln;
    //readln;



   CX := 0;
   nx := 0;
  for i := 1 to n do
  begin
         if x[i] > 0 then
         begin
         CX := CX + x[i];
         nx := nx + 1;
         end;
  end;
  if nx < 1 then writeln (res, 'положительных элементов в массиве X нет, ответ рассчитать невозможно')
  else
  begin
      CX := CX / nx;
   writeln(res, 'CX (среднее арифметическое положительных элементов x) = ', CX:2:3);
  end;

   CY := 0;
   ny := 0;
  for i := 1 to n do
  begin
         if y[i] > 0 then
         begin
         CY := CY + y[i];
         ny := ny + 1;
         end;
  end;
  if ny < 1 then writeln (res, 'положительных элементов в массиве Y нет, ответ рассчитать невозможно')
  else
  begin
      CY := CY / ny;
   writeln(res, 'CY (среднее арифметическое положительных элементов y) = ', CY:2:3);
  end;
       if (ny <> 0) and (nx <> 0) then
       begin
         ANSWER :=   sqrt(CX*CY);
        writeln(res, '√(CX*CY) = ', ANSWER:2:7);
       end;


  end;
  //readln;
  //readln;
  CloseFile(dat); CloseFile(res);
end.
