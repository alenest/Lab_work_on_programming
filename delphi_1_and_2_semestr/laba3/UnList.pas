unit UnList;

interface

type
  TInfo = integer;

  PElem = ^TElem;
  TElem = record
      info: TInfo;
      next: PElem;
  end;
  proc = procedure ( var ListN, listK : Pelem);
  procproc = procedure(var ListN, ListK : Pelem; f1 : proc);

// ������� ������ �� ������ ��������
procedure CreateList(var ListN, ListK: PElem; r: TInfo);
// �������� ����� ������� ����� ������
procedure AddFirst(var ListN: PElem; ListK: PElem; r: TInfo);
// �������� ����� ������� � ����� ������
procedure AddLast(ListN: PElem; var ListK: PElem; r: TInfo);
// �������� ����� ������� � �������� ����� ListC (�� � �����)
procedure AddMedium(ListN,ListC,ListK: PElem; r: TInfo);
// �������� ������
procedure FreeList(var ListN, ListK: PElem);

procedure DeleteLast( var ListN, ListK: Pelem; f: proc);

procedure DeletePos(var ListN, ListK: Pelem; f1: proc);
//procedure DeletePos(var ListN, ListK: Pelem; f1: proc; f2 : procproc);

implementation

// ������� ������ �� ������ ��������
procedure CreateList(var ListN, ListK: PElem; r: TInfo);
begin
  New(ListN);
  ListK:=ListN; // ����� � ������ ���������
  ListN^.info:=r;
  ListN^.next:=nil;
end;

// �������� ����� ������� ����� ������
procedure AddFirst(var ListN: PElem; ListK: PElem; r: TInfo);
var Elem: PElem;
begin
  new(Elem);
  Elem^.info:=r;
  Elem^.next:=ListN;
  ListN:=Elem; // ������ �� 1-��
end;




// �������� ����� ������� � �����
procedure AddLast(ListN: PElem; var ListK: PElem; r: TInfo);
begin
  new(ListK^.next);
  ListK^.next^.info:=r;
  ListK^.next^.next:=nil;
  ListK:= ListK^.next;
end;


// �������� ����� ������� � �������� ����� ListC (�� � �����)
procedure AddMedium(ListN,ListC,ListK: PElem; r: TInfo);
var Elem: PElem;
begin
  new(Elem);
  Elem^.info:=r;
  Elem^.next:=ListC^.next; // ����� ���� ��, ��� ���� ����� ListC
  ListC^.next:=Elem; // � �� ��� ����� ListC
end;

// �������� ������
procedure FreeList(var ListN, ListK: PElem);
var Elem: PElem;
begin
  Elem:=ListN;
  while Elem<>nil do
  begin
    ListN:=ListN^.next;
    Dispose(Elem);
    Elem:=ListN;
  end;
  ListK:=nil;
end;

{procedure DeleteLast( var ListN, ListK : Pelem; f : proc);
var Elem: PElem; IsLast : boolean; counter : integer;
  begin
       IsLast := False;
       Elem:=ListN;
       if (ListN = ListK) then F(ListN, ListK)
       else
       begin
          if(Elem^.next = nil)
          then
       end;
  end;

end.}

procedure DeleteLast( var ListN, ListK: Pelem; f:proc);
var Elem, last: PElem;
begin
  if ListN=nil then writeln ('������ ������, ���������� ������� ��������� �������')
  else if ListN = ListK then
  begin
    f(ListN, ListK); writeln('������ ������ ������');
  end
  else begin

  Elem:=ListN;
      while Elem^.next <> ListK do
      begin
       //writeln('�������� � ������ : ', Elem^.info);
      //if(Elem^.next = ListK) then
        Elem:=Elem^.next;
        //writeln('�������� � ����� : ', Elem^.info);

      end;
      //writeln('����� ����� : ', Elem^.info);
  {if(Elem^.next = ListK) then begin Elem^.next := nil; ListK := Elem; end; }
  last := elem^.next;
  Elem^.next := nil;
  ListK := Elem;
  //Elem := next;
  Dispose(last);
  //ListK:=nil;
   writeln('��������� ������� ������ ������.');

  end;
end;

//procedure DeletePos(var ListN, ListK: PElem; f1 : proc; f2 : procproc);
procedure DeletePos(var ListN, ListK: PElem; f1 : proc);
var Elem, Elem1: Pelem; pos, posC : integer; flag : boolean;
begin
 if ListN=nil then writeln ('������ ������, ������ �������')
 else begin

    write('������� �������, � ������� ����� ������� ������� ������ (k > 0): ');
    pos := -1;
    while pos < 1 do begin readln(pos); if pos < 1 then writeln('������������ �������!'); end;
    posC := 1; Elem := ListN; flag := False;
    while (Elem<>nil) and (not flag) do
    begin
      if pos = 1 then
      begin
        if ListN = ListK then
         begin
            f1(ListN, ListK); write(' ������ ������ ������ ');
            elem := nil;
          end
          else begin
            ListN := ListN.next;
          end ;
         flag := True;
      end
      else if (pos = posC + 1)then
      begin
           Elem1 := Elem;//Elem^.next :=
           Elem:=Elem^.next;
           //Dispose(Elem);
           if Elem1^.next <> nil then Elem1^.next := Elem.next;
           if Elem1^.next = nil then ListK := Elem1;

           flag := True;
      end
      //else if elem^.next = nil then f2(ListN, ListK, f1)
      else Elem:=Elem^.next;

      posC := posC + 1;

    end;
    //if( (elem = nil) and (flag)) then write('������ ������ ������')
    if ((elem = nil) and (ListK <> nil)) then write('����� ������� ���, � ������ ��������� ������')
    else if flag then
     begin
        Dispose(elem);
        Write('������� ������');
     end

     //else writeln('��� ��� ��������� �������. �� ������');

end;
end;

end.

