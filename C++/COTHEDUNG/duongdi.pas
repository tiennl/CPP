{const fi='duongdi.inp';
      fo='duongdi.out';
var f,g:text;
    n,i,j,p,q:longint;
    a:array[1..50,1..50] of integer;
begin
  assign(f,fi);reset(f);
  assign(g,fo);rewrite(g);
  readln(f,n);
  for i:=1 to n do begin
     for j:=1 to n do read(f,a[i,j]);
     readln(f);
  end;
  read(f,p,q);
  close(f);
  close(g);
end.     }


//----------------------------------------------------
type mang=array[0..10000] of longint;
const fi='money.inp';
      fo='money.out';
var f,g:text;
    a,x:mang;
    d,h,h2,k,n,m,p,q,dem:longint;
    b:array[1..1000,1..100] of longint;
procedure kt(x:mang);
  var  t,i:longint;
  begin
     t:=0;
     for i:=1 to k do write(x[i],' ');writeln;
    end;
procedure tohop(i:longint);
   var j:longint;
       // a:mang;
   begin
       x[1]:=a[1];
       x[k+2]:=a[n];
       for j:=x[i-1]+1 to n-k+i do
          begin
             x[i+1]:=a[j+1];
             if i=k then kt(x) else tohop(i+1);
          end;
   end;
begin
  assign(f,fi);reset(f);
  assign(g,fo);rewrite(g);
  readln(f,n,m);
   for h:=1 to n do begin
     for h2:=1 to n do read(f,b[h,h2]);
     readln(f);
  end;
  read(f,p,q);
  fillchar(a,sizeof(a),0);
  for h:=1 to n do a[h]:=h;
  if b[1,5]=1 then inc(dem);
  for h:=1 to n do begin

    k:=h;
    tohop(1);  end;
    readln;
//  write(g,d);
 // close(f);
//  close(g);
end.
//-----------------------------------------------
type mang=array[0..10000] of longint;
const fi='money.inp';
      fo='money.out';
var f,g:text;
    a,x:mang;
    d,h,k,n,m:longint;
procedure kt(x:mang);
  var  t,i:longint;
  begin
     t:=0;
     for i:=1 to k do t:=t+x[i];
     if t=m then inc(d);
    end;
procedure tohop(i:longint);
   var j:longint;
       // a:mang;
   begin
       for j:=x[i-1]+1 to n-k+i do
          begin
             x[i]:=a[j];
             if i=k then kt(x) else tohop(i+1);
          end;
   end;
begin
  assign(f,fi);reset(f);
  assign(g,fo);rewrite(g);
  readln(f,n,m);
  fillchar(a,sizeof(a),0);
  for h:=1 to n do read(f,a[h]);
  sort(1,n);
  d:=0;
  for h:=1 to n do begin
    k:=h;
    tohop(1);  end;
  write(g,d);
  close(f);
  close(g);
end.



