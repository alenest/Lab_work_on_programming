 program laba7;

{$APPTYPE CONSOLE}

{$R *.res}


  //���� - ������� � �������
  // ��� ���-�� ��� � ����Ш�

uses
  Windows,
  System.SysUtils;

  const
  Nmax = 200;

  var
  n, i, u, m: integer;
  otsizmi, nalizmu, sort: boolean;

  promezh, min : currency;
  A, B : array[1..Nmax] of currency;
  test, answer : textFile;

begin
        //setConsoleCP(1251); // ��� ����� ����������� �
        //setConsoleOutputCP(1251);

        //Assignfile(test, ParamStr(1));

        //reset(test);
        //Assignfile(answer, ParamStr(2));

        //rewrite(answer);



       read( n);

       if (n < 1) or (n > Nmax) then writeln( '������������ �������� ��� n')
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
                      if (A[u] < A[u+1]) then
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
                         writeln(#13#10 + '��������� ���: ');
                          for u := 1 to n do write(A[u]:1:0, ' ');
                     end
                     else
                     begin
                         writeln(#13#10 + '����: ');
                          for u := 1 to n do write(A[u]:1:0, ' ');
                     end;



                  i := i + 1;
                end;

                writeln(#13#10 + '������� �������: ');

                sort := False;
                i:=1;
                while (i <= n) and not(sort) do
                begin
                    min :=B[1];
                    m := 1;
                    for u  := 2 to n-i+1 do
                    begin
                         if B[u] < min then
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
                            if B[u] < B[u+1] then sort:=False;

                      end;
                     if sort then
                     begin
                      writeln(#13#10 + '����: ');
                     for u := 1 to n do write(B[u]:1:0, ' ');
                     end
                      else
                      begin
                          writeln(#13#10 + '��������� ���: ');
                      for u := 1 to n do write(B[u]:1:0, ' ');
                      end;

                    i := i + 1;
                end;



        //readln;
        end;


         readln;
        //CloseFile(test);
        //CloseFile(answer);
end.