type mang=array[1..1000] of longint;
var n,i,j:longint;
    d,x:mang;
    f,g:text;
procedure gn(x:mang);
   var j:longint;
   begin
       for j:=1 to n do write(g,x[j],' ');
       writeln(g);
   end;
procedure hv(i:longint);
   var j:longint;
   begin
       for j:=1 to n do
         if d[j]=0 then
          begin
              x[i]:=j;
              d[j]:=1;
              if i=n then gn(x) else hv(i+1);
              d[j]:=0;
          end;
       end;
begin
   assign(f,'huhu.inp');reset(f);
   assign(g,'huhu.out');rewrite(g);
   readln(f,n);
   fillchar(d,sizeof(d),0);
   for n:=1 to 5 do
   hv(1);
   close(f);
   close(g);
end.
