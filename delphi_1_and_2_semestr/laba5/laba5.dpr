program laba5;

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
  n, i, maxm: integer;

  maxproizv, proizv : currency;
  A : array[1..Nmax] of currency;
  test, answer : textFile;

begin
        setConsoleCP(1251); // ��� ����� ����������� �
        setConsoleOutputCP(1251);

        Assignfile(test, ParamStr(1));
        //Assignfile(test, 'C:\Users\user\Desktop\���� 5\����� � �����\test1.txt');
        reset(test);
        Assignfile(answer, ParamStr(2));
        //Assignfile(answer, 'C:\Users\user\Desktop\���� 5\����� � �����\answer.txt');
        rewrite(answer);



       read(test, n);
          if (n < 1) or (n > Nmax) then writeln(answer, '������������ �������� ��� n')
          else
          begin



       for i := 1 to n do read(test, A[i]);

        //maxproizv := exp(2 * ln(A[1]));
        //proizv := abs(A[1])* abs(A[1]);
        proizv := A[1]* A[1];
        maxm  := 1;
        maxproizv := proizv;
        for i := 2 to n do
        begin
                //proizv := proizv * exp(2 * ln(A[i])) ;
                //proizv := proizv * abs(A[i])* abs(A[i]);
                proizv := proizv * A[i]* A[i];
                if (maxproizv < proizv) then
                     begin
                        maxproizv := proizv;
                        maxm := i;
                     end;

        end;



        writeln(answer,'������������ ������������: ', maxproizv:1:4);
        writeln(answer,'����� m, ��� ������� ������������ ������������: ', maxm);

        //readln;
        end;
        CloseFile(test);
        CloseFile(answer);
end.
