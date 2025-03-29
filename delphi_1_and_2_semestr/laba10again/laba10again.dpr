program laba10again;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils;

  const Nmax = 15;
  Type Massiv = array[1..Nmax] of integer;

  procedure Vvod(out N : integer; out A : massiv; out T1, T2: integer);
  var i : integer; test: TextFile;
  begin
    AssignFile(test, ParamSTR(1));
    reset(test);
    read(test, N);
    //read(test);
    for i := 1 to N do read(test, a[i]);
    //read(test);
    read(test, T1,T2);
    closeFile(test);

  end;

  procedure PoiskRamok(const N: integer; const A: massiv; const T1, T2 : integer; out ramkaend, ramkabegin, Nomer: integer);
  var i : integer; flag : boolean;
  begin
       ramkaend := n;
       nomer:= 0;
       ramkabegin := 0;
       if n = 1 then nomer := -3
       else begin
       flag := true;
       i := 1;
       while (i <= n) and flag do
       begin
         if a[i] > T2 then
         begin
          ramkabegin := i;
          flag := false;
         end;
         i := i + 1;
       end;
       //writeln( 'первый цикл ramkabegin = ',ramkabegin);
       //if ramkabegin = 0 then ramkabegin := 1;

       if (ramkabegin = n) then nomer := -2  //первое число, большее числа t2 €вл€етс€ последним числом
       else
       begin
           flag := true;
           i:= ramkabegin + 1;
           while (i <= n) and flag do
           begin
                //writeln('вывожу пройдЄнные циклы ', i);
                if (A[i] < T1) then
                begin
                  ramkabegin :=  i;
                  flag := false;
                end;
                i := i + 1;
           end;
           //writeln( 'второй цикл ramkabegin = ',ramkabegin);
           if flag then nomer := -1 //у нас нет чисел, меньших T1 после T2
           else
           begin  //ищем номер последнего T1
                for i := ramkabegin to n do
                  begin
                    if(a[i] < t1) then ramkaend := i;
                  end;
           end;

       end;
          //readln;
          //writeln( 'ramkabegin = ',ramkabegin);
          //writeln( 'ramkaend = ',ramkaend);
          //writeln( 'nomer = ',nomer);
          //readln;
          end;
    end;


  procedure PoiskNomeraMin(const N: integer; const A: massiv; const T1, ramkaend, ramkabegin: integer; var Nomer: integer);
  var i, min: integer;
  begin
      //writeln('я ¬џѕќЋЌяё—ь');
      //readln;
      //writeln('я ¬џѕќЋЌяё—ь');
      if nomer > -1  then
      begin
           if ramkabegin = ramkaend then
           begin
             Nomer := ramkaend;
             //writeln( 'Ќачало и конец равны, наш номер: ', Nomer);
           end
           else
           begin
                 min := a[ramkabegin];
                 Nomer := ramkabegin;
                       //for(;;)
                 for i := ramkabegin+1 to ramkaend do
                   begin
                      //writeln('вывожу пройдЄнные циклы ', i);
                     if a[i] <= min then
                     begin
                       min :=  a[i];
                       Nomer := i;
                     end;
                   end;
                  // writeln ('»тоговый номер минимального числа, подход€щего под услови€: ', Nomer);
           end;
      end;


      //readln;
  end;


  procedure vivod(N : integer; A: massiv; T1, T2, ramkabegin, ramkaend, nomer: integer);
  var i:integer; answer: TextFile;
  begin
      AssignFile(answer, ParamSTR(2));
      append(answer);

      writeln(answer, #13#10 + '_____________________________________________________________');
      writeln(answer, #13#10 +'¬аш массив: ');
      for i := 1 to N do write(answer,a[i], ' ');
      writeln(answer, #13#10 + '„исло T1: ', T1);
      //writeln(answer, T1);
      writeln(answer, '„исло T2: ', T2);
      //writeln(answer, T2);

      case Nomer of
        -3: begin writeln(answer,#13#10 +'¬ массиве один элемент, дл€ него невозможно проверить критерии'); end;
        -2: begin writeln(answer,#13#10 +'ѕервое число, большее T2, €вл€етс€ последним, следовательно, у нас нет диапазона дл€ поиска чисел, меньших T1');end;
        -1: begin writeln(answer,#13#10 +'ѕосле числа T2 не лежит чисел, меньших T1');end;
        else
        begin

             writeln(answer,#13#10 +'номер минимального числа, лежащего после первого числа, большего T2, и меньшего числа T1: '+ #13#10, nomer);

             writeln(answer,'Ётому номеру соотвествует число: '+ #13#10, a[nomer]);

             //readln;
        end;
      end;
       closeFile(answer);
  end;


  var
  Aa : massiv;
  Nn, Tt1, Tt2, Nnomer, rramkabegin, rramkaend: integer;



begin

  Vvod(Nn, Aa, Tt1, Tt2);
  PoiskRamok(Nn, Aa, Tt1, Tt2, rramkaend, rramkabegin, Nnomer);
  PoiskNomeraMin(Nn, Aa, Tt1, rramkaend, rramkabegin, Nnomer);
  vivod(Nn, Aa, Tt1, Tt2, rramkabegin, rramkaend, nnomer);

  //PoiskRamok( N , A , T1, T2, ramkaT1 , ramkaT2, NomerPriUslovii) ;
  //PoiskNomera (N, A, T1, T2, ramkat1, ramkat2,NomerPriUslovii);
  //Vivod(N, A, T1, T2, ramkat1, ramkat2, NomerPriUslovii);

end.
