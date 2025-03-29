program laba7;

{$APPTYPE CONSOLE}

{$R *.res}


  //ЛАБЫ - ВСТАВКА И ПУЗЫРЕК
  // ИЛИ ЧТО-ТО ТАМ И ПУЗЫРЁК

uses
  Windows,
  System.SysUtils;

  const
  Nmax = 200;

  var
  n, i, u, m: integer;
  otsizmi, nalizmu, sort: boolean;

  promezh, min : ansichar;
  A, B : string[6];
  test, answer : textFile;

begin
        setConsoleCP(1251); // для ввода русификация и
        setConsoleOutputCP(1251);

        //Assignfile(test, ParamStr(1));

        //reset(test);
        //Assignfile(answer, ParamStr(2));

        //rewrite(answer);



       read( n);

       if (n < 1) or (n > Nmax) then writeln( 'Недопустимое значение для n')
       else
          begin

              for i := 1 to n do
              begin
              read(A[i]);
              B[i] := A[i];
              end;
                readln;

                otsizmi := True;
                i := 1;
               while (i <= n) and (otsizmi) do
               begin
                  nalizmu := False;
                  for u := 1 to n-i do
                  begin
                      if (Ord(A[u]) < Ord(A[u+1])) then
                          begin
                              promezh := A[u+1];
                              A[u+1]  := A[u];
                              A[u] := promezh;
                              nalizmu :=  True;
                          end;
                  end;
                   if nalizmu = False then  otsizmi := False;

                     if (otsizmi) then
                     begin
                         writeln(#13#10 + 'следующий шаг: ');
                          for u := 1 to n do write(A[u], ' ');
                     end
                     else
                     begin
                         writeln(#13#10 + 'ИТОГ: ');
                          for u := 1 to n do write(A[u], ' ');
                     end;



                  i := i + 1;
                end;

                writeln(#13#10 + 'Простым выбором: ');

                sort := False;
                i:=1;
                while (i <= n) and not(sort) do
                begin
                    min :=B[1];
                    m := 1;
                    for u  := 2 to n-i+1 do
                    begin
                         if Ord(B[u]) < Ord(min) then
                         begin
                           min := B[u];
                           m := u;
                         end;

                    end;
                    promezh := B[n-i+1];
                    B[n-i+1] := B[m];
                    B[m] := promezh;

                     sort := True;
                    for u := 1 to n-1 do
                      begin
                            if Ord(B[u]) < Ord(B[u+1]) then sort:=False;

                      end;
                     if sort then
                     begin
                      writeln(#13#10 + 'ИТОГ: ');
                     for u := 1 to n do write(B[u], ' ');
                     end
                      else
                      begin
                          writeln(#13#10 + 'следующий шаг: ');
                      for u := 1 to n do write(B[u], ' ');
                      end;

                    i := i + 1;
                end;



        //readln;
        end;


         readln;
        //CloseFile(test);
        //CloseFile(answer);
end.









  //try
    { TODO -oUser -cConsole Main : Insert code here }
  //except
    //on E: Exception do
      //Writeln(E.ClassName, ': ', E.Message);
  //end;
