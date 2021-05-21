Const fi='LPREFIX.INP';
      fo='LPREFIX.OUT';
Var n:longint;
    s:array[1..1000] of string;
Procedure enter;
Var f:text;
    i:longint;
Begin
   Assign(f,fi);
   Reset(f);
   Readln(f,n);
   For i :=1 to n do readln(f,s[i]);
   Close(f);
End;
Function min(a,b:longint):longint;
Begin
   if a>b then min:=b else min:=a;
End;
Procedure process;
Var i,j,k:longint;
    result:string;
    t:array[1..1000] of string;
    count,re,d:longint;
    f:text;
   Begin
   count:=0;
   re:=0;
   d:=0;
   For i:=1 to n-1 do
     For j:=i+1 to n do begin
       count:=0;
       For k:=1 to min(length(s[i]),length(s[j])) do
          if s[i][k]=s[j][k] then
              inc(count)

              else break;
             if count>=re then
                 Begin
                    re:=count;
                    inc(d);
                    t[d]:=copy(s[i],1,count);
                   // break;
                 End;
               end;
   assign(f,fo);rewrite(f);
  // for i:=1 to d do write(f,t[i],' ');
   result:=t[1];
   For i:=2 to d do
       if t[i]<result then result:=t[i];

   Write(f,result);
   Close(f);
End;
Begin
   enter;
   process;
End.

