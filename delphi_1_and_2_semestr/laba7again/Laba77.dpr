program Laba77;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  Windows,
  System.SysUtils;

  var
  i, u, m: integer;
  kodsuchetreg1, kodsuchetreg2: currency;
  otsizmi, nalizmu: boolean;
  promezh: ansichar;
  test, answer: textfile;
  A, B : string[15];

begin
                setConsoleCP(1251); // ��� ����� ����������� �
                setConsoleOutputCP(1251);

                 AssignFile(test,ParamStr(1)); Reset(test);
                 AssignFile(answer,ParamStr(2)); Append(answer);



                readln(test,A);
                B:=A;
                writeln(answer,'--------------------------------------------------------'+#13#10 + '������: ', A);
                writeln(answer,#13#10 + '������� ��������: ');
                writeln(answer,#13#10 + '���� ������: ', A);

                otsizmi := True;
                i := 1;
               while (i <= length(A)) and (otsizmi) do
               begin
                  nalizmu := False;
                  for u := 1 to length(A)-i do
                  begin

                      if ((Ord(A[u]) >= 97) and (Ord(A[u]) <= 122)) or((Ord(A[u]) >= 224) and (Ord(A[u]) <= 255))
                      then kodsuchetreg1:= Ord(A[u]) - 32 +0.5
                      else if(Ord(A[u]) = 168) then kodsuchetreg1:= 197+0.6
                      else if(Ord(A[u]) = 184) then kodsuchetreg1:= 197+0.7
                      else kodsuchetreg1:= Ord(A[u]);


                      if ((Ord(A[u+1]) >= 97) and (Ord(A[u+1]) <= 122)) or((Ord(A[u+1]) >= 224) and (Ord(A[u+1]) <= 255))
                      then kodsuchetreg2:= Ord(A[u+1]) - 32 +0.5
                      else if(Ord(A[u+1]) = 168) then kodsuchetreg2:= 197+0.6
                      else if(Ord(A[u+1]) = 184) then kodsuchetreg2:= 197+0.7
                      else kodsuchetreg2:= Ord(A[u+1]);

                      if (kodsuchetreg1 < kodsuchetreg2) then
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
                         write(answer, 'next step: ');
                          writeln(answer, A);
                     end
                     else
                     begin
                         write(answer,'result: ');
                          writeln(answer,A);
                     end;

                  i := i + 1;
                end;

                writeln(answer, #13#10 +'������� ������: ');
                writeln(answer, #13#10 +'���� ������: ', B);

               for i := length(b) downto 2 do
               begin
                       m:=i; //��� ��� �����������

                      for u := i-1 downto 1 do
                      begin
                            {if ((Ord(B[u]) >= 97) and (ord(B[u]) <= 122 )) or((ord(B[u]) >= 224) and (ord(B[u]) <= 255))
                            then kodsuchetreg1:= Ord(B[u]) - 32 +0.5
                            else kodsuchetreg1:= Ord(A[u]);
                            if ((Ord(B[m]) >= 97) and (Ord(B[m]) <= 122)) or((Ord(B[m]) >= 224) and (Ord(B[m]) <= 255))
                            then kodsuchetreg2:= Ord(B[m]) - 32 +0.5
                            else kodsuchetreg2:= Ord(B[m]);
                            if(Ord(B[u]) = 168) then kodsuchetreg1:= 197+0.6;
                            if(Ord(B[u]) = 184) then kodsuchetreg1:= 197+0.7;
                            if(Ord(B[m]) = 168) then kodsuchetreg2:= 197+0.6;
                            if(Ord(B[m]) = 184) then kodsuchetreg2:= 197+0.7;}

                            if ((Ord(B[u]) >= 97) and (Ord(B[u]) <= 122)) or((Ord(B[u]) >= 224) and (Ord(B[u]) <= 255))
                            then kodsuchetreg1:= ((Ord(B[u]) - 32) +0.5)
                            else if(Ord(B[u]) = 168) then kodsuchetreg1:= (ord('�')+0.6)
                            else if(Ord(B[u]) = 184) then kodsuchetreg1:= ord('�')+0.7
                            else kodsuchetreg1:= Ord(B[u]);


                            if ((Ord(B[m]) >= 97) and (Ord(B[m]) <= 122)) or((Ord(B[m]) >= 224) and (Ord(B[m]) <= 255))
                            then kodsuchetreg2:= ((Ord(B[m]) - 32) +0.5)
                            else if(Ord(B[m]) = 168) then kodsuchetreg2:= (ord('�')+0.6)
                            else if(Ord(B[m]) = 184) then kodsuchetreg2:= (ord('�')+0.7)
                            else kodsuchetreg2:= Ord(B[m]);

                            //writeln(answer,B[u], '      ',B[m]);
                            //writeln(answer,ord(B[u]), '    ',ord(B[m]));
                            //writeln(answer,kodsuchetreg1:1:1, ' ',kodsuchetreg2:1:1);
                            if kodsuchetreg1 < kodsuchetreg2 then
                            begin
                            //writeln(kodsuchetreg1, ' ',kodsuchetreg2);
                            m := u;
                            end;
                            //if b[u] < b[m] then m := u;
                      end;
                      //writeln('����������� �����: ', m,' ');

                       if (m<>i) then
                       begin
                       promezh := b[i];
                       b[i] := b[m];
                       b[m] := promezh;
                       end;

                       //write('next step: ');
                          //writeln(B);
                        write(answer,'next step: ');
                          writeln(answer,B);

               end;

              writeln(answer,'result: ',B);



     CloseFile(test); CloseFile(answer);
end.
