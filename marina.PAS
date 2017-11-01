{ Programm: marina.pas
   }

{$M 16384,0,10000}
program marina

uses Gembind;

var 
  btn: Integer;
    
begin
  if Init_Gem>=0 then
  begin

   
    btn:=Do_Alert('[0]'+
    '[Im love marina.][ Ok ]',1);
    Exit_Gem;
end
  else WriteLn ('o gem não esta na '+
  'memoria !');
end.
