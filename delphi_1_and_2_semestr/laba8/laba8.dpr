program laba8;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils;

    const
      nmax = 10;

    var
      i,j,n, count : integer;
      test, answer : textfile;
      predzn, promezh : currency;
      a : array[1..nmax,1..nmax] of currency;

begin
     AssignFile(test, ParamSTR(1));
     reset(test);
     AssignFile(answer, ParamSTR(2));
     append(answer);



     read(test, n);
     read(test);


      for i := 1 to n do
      begin
          for j := 1 to n do read(test,a[i,j]);
          readln(test);

      end;

      writeln(answer, '--------------------------------------');
      writeln(answer, '���� �������: ');
      writeln(answer);
      for i := 1 to n do
     begin

          for j := 1 to n do write(answer, a[i,j]:5:1, ' ');

           writeln(answer);

     end;

      writeln(answer);
      writeln(answer, '���������� �������: ');
      writeln(answer);

      //readln;
     count := 0;
     for i := 1 to n do
     begin
          predzn := a[i,1];
          if (a[i,1] < 0) then
          begin
          a[i,1] := a[i,1] + a[i,n];
          count := count + 1;
          end;

          for j := 2 to n do
          begin
              if a[i,j] < 0 then
              begin
                  promezh := a[i,j];
                  a[i,j]  := a[i,j] + predzn ;
                  predzn := promezh;
                  count := count + 1;

              end
              else predzn := a[i,j];

          end;

     end;

      //readln;

   for i := 1 to n do
     begin

          for j := 1 to n do write(answer, a[i,j]:5:1, ' ');

           writeln(answer);

     end;
     writeln(answer);
     writeln(answer, '���������� ���������: ', count);
     //writeln(answer);
      //readln;
      CloseFile(test); CloseFile(answer);
end.
