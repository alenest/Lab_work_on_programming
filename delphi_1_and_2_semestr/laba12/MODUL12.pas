unit MODUL12;

interface

const Nmax = 5;
  Type matrix = array[1..Nmax,1..Nmax] of currency; //��� ������������� ������������ �����

  procedure vvodmatrix(var testt: TextFile;const nn : byte; out aa:matrix);

  procedure vivodmatrix(var answerr: TextFile; const Nn : integer; var Aa : matrix);

  function checkmatrix(const nn: byte; const aa : matrix; out ii, jj : byte) : boolean;

  function checkusl(const Nn: byte; const Aa : matrix) : boolean;

  function PoiskSumVerhDiag(const Nn : byte; const Aa: matrix) : currency;

implementation

  procedure vvodmatrix(var testt: TextFile;const nn : byte; out aa:matrix);
  var  i, j : byte;
  begin
    for i := 1 to nn do
    begin
          for j := 1 to nn do read(testt,aa[i,j]);
          readln(testt);
      end;
  end;

  procedure vivodmatrix(var answerr: TextFile; const Nn : integer; var Aa : matrix);
  var i,j : integer;
  begin
    writeln(answerr, '�������: '+ #13#10);
    for i := 1 to Nn do
    begin
       for j := 1 to Nn do write(answerr,Aa[i][j]:3:3, '    ');
       writeln(answerr);
    end;
    writeln(answerr);

  end;

  function checkmatrix(const nn: byte; const aa : matrix; out ii, jj : byte) : boolean;
  var flag : boolean; i, j : byte;
  begin
      flag := True;
      ii := 0; jj:=0;
      i := 1;
      while (i <= nn) and (flag) do
      begin
         j:= 1;
         while (j <= nn) and (flag) do
         begin
            if (aa[i][j] < -100) or (aa[i][j] > 100) then
            begin
               ii := i; jj := j;
               flag := False;
            end;

            j := j + 1;
         end;
         i:= i + 1;

      end;
      checkmatrix := flag;

  end;

  function checkusl(const Nn: byte; const Aa : matrix) : boolean;
  var flag : boolean; i, j : byte; counter : integer;
  begin
      flag:= true;
      j := 1;
      while (j <= nn) and (flag) do
      begin
         i:= 1;
         counter := 0;
         while (i <= nn) and (flag) do
         begin
            if aa[i][j] = 0 then
            begin
              counter := counter + 1;

            end;
            if counter > 1 then flag := False;
            i := i + 1;
         end;
         j:= j + 1;

      end;

      checkusl := flag;

  end;

  function PoiskSumVerhDiag(const Nn : byte; const Aa: matrix) : currency;
  var sum : currency; i, j : byte;
  begin
       sum := 0;
       for i := 1 to nn do
       begin
         j := i;
         while j <= nn do
         begin
            sum := sum + aa[i][j];
            j := j + 1;
         end;
       end;
       PoiskSumVerhDiag := sum;
  end;


end.
