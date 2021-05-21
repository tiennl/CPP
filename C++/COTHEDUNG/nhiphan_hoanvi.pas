type mang=array[1..10000] of longint;
var x:mang;
    k,n:longint;
    g:text;
procedure kt(x:mang);
  var  i,k:longint;
  begin
     for i:=1 to n do  write(g,x[i],' ');
     writeln(g);

  end;

procedure hvi(i:longint);
   var j:longint;
   begin
       for j:=1 to 2 do
          begin
             x[i]:=j;
             if i=n then kt(x) else hvi(i+1);
          end;
   end;

begin
assign(g,'Hoanvi.out');Rewrite(g);
    for n:=1 to 5 do
    hvi(1);

end.
