Unit UnLAB1;      // им€ модул€ Ц мен€етс€ при сохранении File ? Save AsЕ
Interface       // раздел описани€ межмодульного интерфейса

Uses
  SysUtils;

Const
  //SymbTable = '0123456789јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёяzyxwvutsrqponmlkjihgfedcba';
  SymbTable = '0123456789јаЅб¬в√гƒд≈е®Є∆ж«з»и…й кЋлћмЌнќоѕп–р—с“т”у‘ф’х÷ц„чЎшўщЏъџы№ьЁэёюя€ZYXWVUTSRQPONMLKJIHGFEDCBA';

Const
  Cifr : set of '0'.. '9' = ['0'.. '9'];
  //BukvKir: set of char = ['ј'..'я', '®', 'a'..'z', 'Є'];
  //BukvKir: set of char = ['ј'..'≈', '®','∆' .. 'я', 'а'..'е', 'Є','ж' .. '€'];
  //#13#10
  BukvKir: set of ansichar = [#192 .. #255, #168, #184];
  //BukvKir: set of ansichar = [#192];
  BukvLat: set of ansichar = ['A'..'Z'];

Function Prov1(const s: ansiString): Byte; // проверка без SymbTable
Function Prov2(const s: ansiString): Byte; // проверка с SymbTable
Procedure Sort1(var s: ansiString);  // сортировка без SymbTable
Procedure Sort2(var s: ansiString);  // сортировка с SymbTable

Implementation  // раздел реализации и описани€ закрытых процедур

Function Prov1(const s: ansiString): Byte; // проверка без SymbTable
Var
  Nom: byte; // номер аномалии
  i,Len: word; // текущий символ и длина строки
Begin
  {writeln(#13#10, ord('ј'));
  writeln(#13#10, ord('я'));
  writeln(#13#10, ord('а'));
  writeln(#13#10, ord('€'));
  writeln(#13#10, ord('®'));
  writeln(#13#10, ord('Є')); }
  Nom:=0; len:= Length(S);
  If Len=0 then Nom:=1
  Else
    Begin
      i:=1;
      while (i<=Len) and (Nom=0) do
      begin
        if Not ((S[i] in Cifr) or (S[i] in BukvKir) or (S[i] in BukvLat)) then Nom:=2;
        Inc(i);
      end;
    End;
  Prov1:=Nom;
End;

Function Prov2(const s: ansiString): Byte; // проверка с SymbTable
Var


  Nom: byte; // номер аномалии
  i,Len: word; // текущий символ и длина строки
Begin
  Nom:=0; len:= Length(S);
  If Len=0 then Nom:=1
  Else
    Begin
      i:=1;
      while (i<=Len) and (Nom=0) do
      begin
        if Not (Pos(S[i], SymbTable)>0) then Nom:=2;
        Inc(i);
      end;
    End;
  Prov2:=Nom;
End;

Procedure Sort1(var s: ansiString);  // сортировка без SymbTable
Var
  i, z, len: Word; // номер текущего символа, номер итерации (шага), длина строки
  flag: Boolean; // упор€дочено? (нет обменов?)
  ch: ansichar; // дл€ обмена
Begin
  Z:=1;  len:=length(s);
  Repeat // пузырЄк
    flag:=true;
    for i:=1 to len-z do
      if (s[i] in BukvLat) and ((s[i+1] in Cifr) or (s[i+1] in BukvKir)) or    //латинские буквы Ђлегчеї всех
         (s[i] in BukvKir) and (s[i+1] in Cifr) or       // кириллица Ђлегчеї цифр Ц всплывает
         (s[i] in Cifr) and (s[i+1] in Cifr) and (s[i]>s[i+1]) or     // обе цифры Ц по возрастанию
         (s[i] in BukvLat) and (s[i+1] in BukvLat) and (s[i]<s[i+1])    // обе латинские буквы Ц от z до a
      then
      begin // обмен
        ch:=s[i]; s[i]:=s[i+1]; s[i+1]:=ch; flag:= false;
      end;
    inc(z);
  Until flag or (z=len);
End;

Procedure Sort2(var s: ansiString);  // сортировка с SymbTable
Var
  i, z, len: Word; // номер текущего символа, номер итерации (шага), длина строки
  flag: Boolean; // упор€дочено? (нет обменов?)
  ch: ansichar; // дл€ обмена
Begin
  z:=1;  len:=length(s);
  Repeat // пузырЄк
    flag:=true;
    for i:=1 to len-z do
      if (Pos(s[i], SymbTable) > Pos(s[i+1], SymbTable))  // неправильный пор€док по своей Ђтаблицеї
        and not ((s[i] in BukvKir) and (s[i+1] in BukvKir)) // но кириллицу не упор€дочивать
      then
      begin // обмен
        ch:=s[i]; s[i]:=s[i+1]; s[i+1]:=ch; flag:= false;
      end;
    inc(z);
  Until flag or (z=len);
End;

end.

