program laba11;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils;

const Nmax = 10;
  Type matrix = array[1..Nmax,1..Nmax] of currency;

  procedure Vvod(out test: textfile; out N : integer; out A : matrix);
  var i, j : integer;
  begin

    read(test, N);
    for i := 1 to n do
      begin
          for j := 1 to n do read(test,a[i,j]);
          readln(test);

      end;
       read(test);

    //read(test);



  end;

  procedure transformation(const N : integer; var A : matrix; out counter: integer);
  var predzn: currency; i, j : integer;
  begin
      counter:= 0;
     for i := 1 to n do
      begin
          predzn:= a[i][1];
          for j := 2 to n do
          begin
               if (a[i][j] < 0 ) then
               begin
                  a[i][j] := a[i][j] + predzn;
                  counter:= counter + 1;
               end;
               predzn:= a[i][j];
          end;
          if (a[i][1] < 0 ) then
          begin
             a[i][1] := a[i][1] + predzn;
             counter:= counter + 1;
          end;


      end;

  end;

  procedure vivodmatrix(const N : integer; var A : matrix);
  var answer: TextFile; i,j : integer;
  begin
    AssignFile(answer, ParamSTR(2));
    append(answer);
    writeln(answer, '�������� �������: '+ #13#10);
    for i := 1 to N do
    begin
       for j := 1 to N do write(answer,A[i][j]:6:2, '  ');
       writeln(answer);
    end;
    writeln(answer);
     closeFile(answer);
  end;

  procedure vivoizmdmatrix(const N : integer; var A : matrix; out counter: integer);
  var answer: TextFile; i,j : integer;
  begin
    AssignFile(answer, ParamSTR(2));
    append(answer);
    writeln(answer,#13#10 + '���������� �������: ' + #13#10 );
    for i := 1 to N do
    begin
       for j := 1 to N do write(answer,A[i][j]:6:2, '  ');
       writeln(answer);
    end;
    writeln(answer,#13#10 +'���������� ���������: ', counter);
     writeln(answer);
     closeFile(answer);
  end;

 //const Nmatrix = 3;
 procedure max(const counter1, counter2, counter3 : integer; out maxim: integer);
 begin

    maxim := counter1;
    if maxim < counter2 then maxim :=  counter2;
    if maxim < counter3 then maxim :=  counter3;
 end;

var
n1, n2, n3 : integer;
A1, A2, A3: matrix;
izm1, izm2, izm3 : integer;
i, maxizm : integer;
answer, test: TextFile;
begin

   AssignFile(test, ParamSTR(1));
    reset(test);


  Vvod(test, N1, A1);
  VivodMatrix(N1, A1);
  transformation(N1, A1 , izm1);
  vivoizmdmatrix(N1, A1, izm1);

  Vvod(test, N2, A2);
  VivodMatrix(N2, A2);
  transformation(N2, A2 , izm2);
  vivoizmdmatrix(N2, A2, izm2);

  Vvod(test, N3, A3);
  VivodMatrix(N3, A3);
  transformation(N3, A3 , izm3);
  vivoizmdmatrix(N3, A3, izm3);

   AssignFile(answer, ParamSTR(2));
   append(answer);

    max(izm1, izm2, izm3, maxizm);
    if maxizm = 0 then writeln(answer,#13#10 +'��������� �� ���� ��� �������� ���')
    else
    begin
         writeln(answer,#13#10 +'������������ ����� ���������: ', maxizm, #13#10 + '��� ������������ ���������� ���������' );
         if maxizm = izm1 then writeln(answer,'� ������ �������');
         if maxizm = izm2 then writeln(answer,'�� ������ �������');
         if maxizm = izm3 then writeln(answer,'� ������� �������');

    end;





   writeln(answer, #13#10 + '_____________________________________________________________');
   closeFile(answer);
   closeFile(test);

end.
