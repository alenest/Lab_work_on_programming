program laba9;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils;

const

  nmax = 10;

  var
  i, j, ibeznul, errortype, n1, n2 : integer;
  test, answer : TextFile;
  ObcsheeUslovie, NalichieNulyaVStroke : boolean;
   a : array[1..nmax,1..nmax] of currency;

//"C:\Users\user\Desktop\laba9\Test and Answer\test1.txt" "?C:\Users\user\Desktop\laba9\Test and Answer\answer.txt"
//"C:\Users\user\Desktop\laba9\Test and Answer\test_with_wrong_data.txt" "C:\Users\user\Desktop\laba9\Test and Answer\answer.txt"

begin
  errortype := 0;
  {For i:=0 to ParamCount do writeln('Param',i:2,' ', ParamStr(i));
  Write('Press ENTER'); ReadLN;}
  //readln;
  try // ������ ������� ���� �� ������

  //readln;
      //AssignFile(test, 'C:\Users\user\Desktop\laba9\Test and Answer\ttest_with_wrong_data.txt');
      //C:\Users\user\Desktop\laba9\Test and Answer\test1.txt
     AssignFile(test, ParamSTR(1));
     //AssignFile(test,'C:\Users\user\Desktop\laba9\Test and Answer\test1.txt' );
     reset(test);
     try
      try
        read(test,n1);
        read(test,n2);
       for i := 1 to n1 do
        begin
          for j := 1 to n2 do read(test,a[i,j]);
          readln(test);
        end;

           //C:\Users\user\Desktop\laba9\Test and Answer\answer.txt
           //AssignFile(answer, ParamSTR(2));
           AssignFile(answer, 'C:\Users\user\Desktop\laba9\Test and Answer\answer.txt');
           append(answer);
            writeln(answer, '----------------------------------------------------------------------------------');
            writeln(answer, '���� �������: ');
            writeln(answer);
            for i := 1 to n1 do
            begin

          for j := 1 to n2 do write(answer, a[i,j]:5:1, ' ');

              writeln(answer);

          end;
          //��� �������� ���������


          ObcsheeUslovie := True;
          i := 1;
          while((i <= n1) and (ObcsheeUslovie)) do
          begin

               NalichieNulyaVStroke := False;
               j := 1;
               while((j <= n2) and not(NalichieNulyaVStroke)) do
               begin
                  if (a[i,j] = 0) then NalichieNulyaVStroke := True;
                  j := j + 1;
               end;

               if not(NalichieNulyaVStroke) then
               begin
                ObcsheeUslovie := False;
                 ibeznul  := i;
               end;
              i := i + 1;
          end;
          writeln(answer);
          //��� �������
          if ObcsheeUslovie then writeln(answer, '� ������ ������ ������� ���� ���� �� ���� ������� �������')
          else  begin writeln(answer, '�� � ������ ������ ������� ���� ���� �� ���� ������� �������') ;
                writeln(answer,'������ ������ ��� ������� ���������: ', ibeznul ) ;  end;


          Closefile(answer);





      except
       errortype := 2;
      end;
     finally
         Closefile(test);
     end;
  except
      //writeln('pampampam');
      errortype := 1;
  end;
  //writeln('blyaaaaaaaaaaaa');
  //readln;
  case errortype of
  1: begin writeln('�� ������� ������� ���� ��� ���������� ������'); readln; end;//writeln('�� ������� ������� ���� ��� ���������� ������');
  2: begin writeln('������ ����� �� �����'); readln; end;
  end;

  //readln;
  //writeln('xnj-nj gbitncz');


end.
