{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils;

const Nmax = 10;
  Type matrix = array[1..Nmax,1..Nmax] of currency;

  procedure Vvod(out Nn1 : integer; out Aa1 : matrix; out Nn2 : integer; out Aa2 : matrix; out Nn3 : integer; out Aa3 : matrix);
  var i, j : integer; test: textfile;
  begin
    AssignFile(test, ParamSTR(1));
    reset(test);
    read(test, Nn1);
    for i := 1 to nn1 do
      begin
          for j := 1 to nn1 do read(test,aa1[i,j]);
          readln(test);

      end;
       read(test);
      read(test, Nn2);
    for i := 1 to nn2 do
      begin
          for j := 1 to nn2 do read(test,aa2[i,j]);
          readln(test);

      end;
       read(test);
      read(test, Nn3);
    for i := 1 to nn3 do
      begin
          for j := 1 to nn3 do read(test,aa3[i,j]);
          readln(test);

      end;
    //read(test);

      closeFile(test);

  end;

  function counter(const N : integer; var A : matrix):integer;
  var predzn: currency; i, j : integer;
  begin
     result := 0;
     for i := 1 to n do
      begin
          predzn:= a[i][1];
          for j := 2 to n do
          begin
               if (a[i][j] < 0 ) then
               begin
                  a[i][j] := a[i][j] + predzn;
                  result:= result + 1;
               end;
               predzn:= a[i][1];
          end;
          if (a[i][1] < 0 ) then
          begin
             a[i][1] := a[i][1] + predzn;
             result:= result + 1;
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
 function max(const counter1, counter2, counter3 : integer) : integer;
 begin

    result := counter1;
    if result < counter2 then result :=  counter2;
    if result < counter3 then result :=  counter3;
 end;

var
n1, n2, n3 : integer;
A1, A2, A3: matrix;
izm1, izm2, izm3 : integer;
i, maxizm : integer;
answer: TextFile;
begin


  Vvod(N1, A1, N2, A2, N3, A3);


  VivodMatrix(N1, A1);
  izm1 := counter(N1, A1);
  vivoizmdmatrix(N1, A1, izm1);


  VivodMatrix(N2, A2);
  izm2 := counter(N2, A2);
  vivoizmdmatrix(N2, A2, izm2);

  VivodMatrix(N3, A3);
  izm3 := counter(N3, A3);
  vivoizmdmatrix(N3, A3, izm3);

   AssignFile(answer, ParamSTR(2));
   append(answer);

    maxizm := max(izm1, izm2, izm3);
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

end.
