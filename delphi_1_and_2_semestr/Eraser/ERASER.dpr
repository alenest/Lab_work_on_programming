program ERASER;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils;

var
  answer : TextFile;

begin

      AssignFile(answer,ParamSTR(1));
      rewrite(answer);
      closeFile(answer);

end.
