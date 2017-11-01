{ Programm:  loto.pas
   }

{$M 16384,0,10000}
program loto;

uses Gembind;

var 
  n: Integer;
  a: Integer;
  btn: Integer;
  s1:String;
     s2:String;
begin

if Init_Gem>=0 then 
 begin 
  
s1:='[0][';
for a := 0  to 8 do
begin
n:=random(49)+1;
Str(n,s2);
s1:=s1 + s2;
s1:=s1 +'  '
   end;
 s1:=Concat(s1 , '.][ Ok ]');
 (* writeln(s1); *)
 
 btn:=Do_Alert(s1,1); 
    
    
end 

end.
