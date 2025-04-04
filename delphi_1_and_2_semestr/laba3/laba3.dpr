program laba3;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Windows,
  UnList in 'UnList.pas',   // ���������� ������ � ������ � �����������, � ����� � � �����������
  UnVar in 'UnVar.pas';

// �������� ������� �� ��������� R � ������������ � �������� �������� � ������
procedure AddR(var ListN, ListK: PElem; r: TInfo); // ������ ������ � ����� ������ � R
var ListC: PElem;  // ������� ������� ������
begin
  if ListN = nil then CreateList(ListN, ListK, r)  // ���� ������ ����
  else
    if (r) <= (ListN^.info) then AddFirst(ListN, ListK, r)  // �������� � ������
    else
       if (r) >= (ListK^.info) then AddLast(ListN, ListK, r)  // �������� � �����
       else
         begin // ����� ����� ������
           ListC:=ListN; // � ������ ������
           while (ListC^.next^.info) <= (r) do
             ListC := ListC^.next;
           AddMedium(ListN, ListC, ListK, r)  // �������� ����� ��������
         end;
end;

//  "�������� ��������������� N ���������" � ������� ������
procedure AddN;
var n,i: integer; s:string; r: TInfo;
begin
  write('������� N=?'); readln(s);
  if not TryStrToInt(s,n) then n:=1;
  for i:=1 to n do
  begin
    r:= (10 + Random(1000-10+1));
    AddR(NachaloSpiska, KonecSpiska, r);
  end;
  writeln('�������� ���������');
end;

// ���������� ���� ������ �� ���������� ����� � ������� ������
procedure AddFromTextFile;
var
  f: TextFile;
  r: TInfo;
begin
  //if ParamCount=1 then writeln('������� �������� � Ctrl+Z') ;

  AssignFile(f, ParamStr(1));
  try
    Reset(f);
    try
      try
          while not eof(f) do
          begin
            readln(f, r);
            AddR(NachaloSpiska, KonecSpiska,r);
          end;
          writeln('������ ������');
      except
       writeln('������������ ������ � ��������� ����� '+ ParamStr(1));
      end;
    finally
      CloseFile(f);
    end;
  except
    writeln('�� ������� ������� ��������� ���� '+ ParamStr(1));
  end;
end;

// �������� ���� �������  � ������� ������
procedure Add1;
var
  r: TInfo;
begin
 try
  write('������� ����� ����� R=?'); readln(r);
  AddR(NachaloSpiska, KonecSpiska, r);
 except
    writeln('������������ ����� ��� ������ ����������');
 end;
end;

// "����� � ������"
procedure SearchIt;
var
  ListC: PElem;
  flag : boolean;
begin
         // ���� - ����� � ����� ����������
         // ��� �������� ��������� ������ ����������� ����
  ListC:=NachaloSpiska;
  flag := False;
  while (ListC<>nil) and (not flag) do   // ��� while (ListC<>nil) and not flag do
  begin
             // ����� �������� ������� ������� � ���������� � ��� ListC^.info
    if (ListC^.info mod 2 <> 0)  then
    begin
      writeln('������ �������� ������� � ������: ', ListC^.info);
      flag := True;
    end;

    ListC:=ListC^.next;
  end;
  if not flag then writeln('�������� ��������� � ������ ���');


end;

//  "��� ������ � ������?" - ����� �� ����� �������
procedure ViewList;
var
  ListC: PElem;
begin
  writeln('������:');
  ListC:=NachaloSpiska;
  if ListC=nil then writeln('������');
  while ListC<>nil do
  begin
    writeln(ListC^.info);
    ListC:=ListC^.next;
  end;
end;

//--------------------������� ���������-------------------------
var
  ch: char;
begin
  SetConsoleCP(1251);      // �� ������ Windows
  SetConsoleOutputCP(1251);

{ ��� ����, ����� ������ ��� ��� ������� ��������� ��������������
  ����� ������������������ ��������������� �����.
  ���� � �� �� ������������������ ������ ��� ������� ���������. }
  Randomize;

  repeat
    writeln('--------------------------------------');
    writeln('Q - �������� � ������ �� ���������� �����; ');
    writeln('W - ������������� � �������� � ������; ');
    writeln('E - �������� � ������; ');
    writeln('R - ����� � ������;');
    writeln('T - �������(��������) ������;');
    writeln('Y - ��������;');
    writeln('U - �����.');
    writeln('K - ������� K-�� �������');
    writeln('D - ������� ��������� �������');

    write('��� �����? '); readln(ch);
    writeln('--------------------------------------');

    ch:= UpCase(ch);
    case ch of
//----------������� ������ �� ���������� �����------------------
    'Q': AddFromTextFile;
//----------������������� ������ -------------------------------
    'W': AddN;
//----------�������� � ������ ----------------------------------
    'E': Add1;
//-----------�����----------------------------------------------
    'R': SearchIt;
//-----------������������ ������--------------------------------
    'T': FreeList(NachaloSpiska, KonecSpiska);
//-----------��������----------------------------------------------
    'Y': ViewList;
//-----------�����----------------------------------------------
    'U': exit;
//--------------------------------------------------------------
     'K' : DeletePos(NachaloSpiska, KonecSpiska, FreeList);
     //'K' : DeletePos(NachaloSpiska, KonecSpiska, FreeList, DeleteLast);
     'D': DeleteLast(NachaloSpiska, KonecSpiska, FreeList);



      else
        begin
          writeln('��� ����� �������');
          write('Press ENTER'); readln;
        end;
    end;

  until ch='U';
end.

