program laba10;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils;


  const Nmax = 15;
  Type Massiv = array[1..Nmax] of integer;


  procedure Vvod(var Nn : byte; var Aa : massiv; var Tt1, Tt2: integer);
  var i : byte;
  begin
    read(Nn);
    for i := 1 to Nn do read(aa[i]);
    read(Tt1,Tt2);

  end;

  {procedure PoiskNomeraPoT2(const Nn : byte; const Aa : massiv; const Tt1: integer; const Tt2 : integer; out uslT2: byte; out usl1T1 : integer; out nomer : byte);
  var i : byte; flag : boolean;
  begin
      uslT2 := 1;

      i := 1;
      flag := True;
      while (i <= Nn) and flag do
      begin
           if Aa[i] > Tt2 then  begin uslT2 := i; flag := False; end;
           i := i + 1;
      end;

      if

  end;}

  procedure PoiskRamok(const Nn: byte;  Aa : massiv;  Tt1, Tt2: integer; out ramkaTt1, ramkaTt2 : byte;  Nomer : integer) ;
  var i : byte; flag : boolean;
  begin
    nomer := 0;
    ramkaTt1 := 0;
    ramkaTt2 := 1;

    i := 1;
    flag := True;
    while (i <= Nn) and flag do
      begin
         if(aa[i] > Tt2 ) then
         begin
            ramkaTt2 := i;
             flag := False;
             //min := aa[i];
         end;
        i := i + 1;
       end;

        writeln (' рамка т2: ', ramkatt2);

      if (ramkaTt2 = Nn) then Nomer := -2
      else
      begin

          //flag := True;
          for i := ramkaTt2+1 to Nn do
          begin
            if aa[i] < Tt1 then ramkaTt1 := i;

          end;
          if (ramkaTt1 = 0) then nomer := -1;

      end;
      writeln (' рамка т1: ', ramkatt1);


  end;

  {procedure PoiskNomeraPoT1(const Nn : byte; const Aa : massiv; const Tt1 : integer; const uslT2 : byte; out uslT1: integer);
  var i : byte; flag : boolean; min : integer;
  begin
       uslT1 := 0;

       i := uslT2;
       while (i <= Nn) and flag do
       begin
         if(aa[i] < Tt1) then
         begin
            uslT1 := i;
             flag := False;
             //min := aa[i];
         end;
        i := i + 1;
       end;

       if (uslT1 <> 0) then
       begin
           for i := uslT1 + 1 to Nn do
           begin
                if Aa[i] <= Aa[uslT1] then uslT1 := i;
           end;
       end;

  end;}

  procedure PoiskNomera(const Nn : byte; Aa : massiv; Tt1, Tt2 : integer; ramkaTt1, RamkaTt2 : byte; var Nomer : integer);
  var i : byte; min : integer;
  begin
        if nomer > -1 then
        begin
            min := Tt1;
            for i := ramkatt2 to ramkatt1 do
              begin
                 if (aa[i] <= min) then
                 begin
                      min := aa[i];
                      nomer := i;
                 end;

              end;


        end;


  end;

  {procedure Vivod(out Nn:byte; Aa: massiv; out Tt1, Tt2 : integer; out usl1: byte);
  var i : byte;
  begin
    readln;
    writeln('_______________________________________________________________________________');
    //writeln('',Nn);
    writeln('Ваш массив:');

    for i := 1 to Nn do write(' ',aa[i]);
    writeln('T1: ', Tt1,' T2: ',Tt2);

    if (usl1 = 0) then writeln('Нет чисел, меньших T1')
    else writeln('номер: ', usl1);
  end;}

  procedure Vivod( const Nn : byte; Aa : massiv; Tt1, Tt2 : integer; ramkaTt1, RamkaTt2 : byte; Nomer : integer);
  var i : byte;
  begin
      readln;
    writeln('_______________________________________________________________________________');
    writeln('Ваш массив:');
     for i := 1 to Nn do write(' ',aa[i]);
    writeln(' T1: ', Tt1,' T2: ',Tt2);
    if (nomer = -2) then writeln ('Первое число, большее T2, оказалось последним, следовательно, у нас нет диапазона для поиска чисел, меньших T1')
    else if nomer = -1 then  writeln ('Не нашлось чисел, меньших T1')
    else writeln('номер: ', nomer);

  end;


  var
  A : massiv;
  T1, T2, NomerPriUslovii : integer;
  N, i, ramkaT1, ramkaT2 : byte;
  //NomerUslovT1 : real;
  //test, answer: textfile;

begin
  Vvod(N, A, T1, T2);
  PoiskRamok( N , A , T1, T2, ramkaT1 , ramkaT2, NomerPriUslovii) ;
  PoiskNomera (N, A, T1, T2, ramkat1, ramkat2,NomerPriUslovii);
  Vivod(N, A, T1, T2, ramkat1, ramkat2, NomerPriUslovii);

  //PoiskNomeraPoT2(N, A, T1, T2, ramkaT2, ramkaT1, NomerPriUslovii);
  //PoiskRamok();
  //PoiskNomeraPoT1(N, A, T1, NomerUslovT2, NomerUslovT1);
  //Vivod(N, A, T1, T2, NomerUslovT1);
  readln;
end.
