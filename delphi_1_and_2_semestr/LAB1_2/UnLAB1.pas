Unit UnLAB1;      // ��� ������ � �������� ��� ���������� File ? Save As�
Interface       // ������ �������� ������������� ����������

Uses
  SysUtils;

Const
  //SymbTable = '0123456789�����Ũ��������������������������zyxwvutsrqponmlkjihgfedcba';
  SymbTable = '0123456789�����������娸����������������������������������������������������ZYXWVUTSRQPONMLKJIHGFEDCBA';

Const
  Cifr : set of '0'.. '9' = ['0'.. '9'];
  //BukvKir: set of char = ['�'..'�', '�', 'a'..'z', '�'];
  //BukvKir: set of char = ['�'..'�', '�','�' .. '�', '�'..'�', '�','�' .. '�'];
  //#13#10
  BukvKir: set of ansichar = [#192 .. #255, #168, #184];
  //BukvKir: set of ansichar = [#192];
  BukvLat: set of ansichar = ['A'..'Z'];

Function Prov1(const s: ansiString): Byte; // �������� ��� SymbTable
Function Prov2(const s: ansiString): Byte; // �������� � SymbTable
Procedure Sort1(var s: ansiString);  // ���������� ��� SymbTable
Procedure Sort2(var s: ansiString);  // ���������� � SymbTable

Implementation  // ������ ���������� � �������� �������� ��������

Function Prov1(const s: ansiString): Byte; // �������� ��� SymbTable
Var
  Nom: byte; // ����� ��������
  i,Len: word; // ������� ������ � ����� ������
Begin
  {writeln(#13#10, ord('�'));
  writeln(#13#10, ord('�'));
  writeln(#13#10, ord('�'));
  writeln(#13#10, ord('�'));
  writeln(#13#10, ord('�'));
  writeln(#13#10, ord('�')); }
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

Function Prov2(const s: ansiString): Byte; // �������� � SymbTable
Var


  Nom: byte; // ����� ��������
  i,Len: word; // ������� ������ � ����� ������
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

Procedure Sort1(var s: ansiString);  // ���������� ��� SymbTable
Var
  i, z, len: Word; // ����� �������� �������, ����� �������� (����), ����� ������
  flag: Boolean; // �����������? (��� �������?)
  ch: ansichar; // ��� ������
Begin
  Z:=1;  len:=length(s);
  Repeat // ������
    flag:=true;
    for i:=1 to len-z do
      if (s[i] in BukvLat) and ((s[i+1] in Cifr) or (s[i+1] in BukvKir)) or    //��������� ����� ������ ����
         (s[i] in BukvKir) and (s[i+1] in Cifr) or       // ��������� ������ ���� � ���������
         (s[i] in Cifr) and (s[i+1] in Cifr) and (s[i]>s[i+1]) or     // ��� ����� � �� �����������
         (s[i] in BukvLat) and (s[i+1] in BukvLat) and (s[i]<s[i+1])    // ��� ��������� ����� � �� z �� a
      then
      begin // �����
        ch:=s[i]; s[i]:=s[i+1]; s[i+1]:=ch; flag:= false;
      end;
    inc(z);
  Until flag or (z=len);
End;

Procedure Sort2(var s: ansiString);  // ���������� � SymbTable
Var
  i, z, len: Word; // ����� �������� �������, ����� �������� (����), ����� ������
  flag: Boolean; // �����������? (��� �������?)
  ch: ansichar; // ��� ������
Begin
  z:=1;  len:=length(s);
  Repeat // ������
    flag:=true;
    for i:=1 to len-z do
      if (Pos(s[i], SymbTable) > Pos(s[i+1], SymbTable))  // ������������ ������� �� ����� ��������
        and not ((s[i] in BukvKir) and (s[i+1] in BukvKir)) // �� ��������� �� �������������
      then
      begin // �����
        ch:=s[i]; s[i]:=s[i+1]; s[i+1]:=ch; flag:= false;
      end;
    inc(z);
  Until flag or (z=len);
End;

end.

