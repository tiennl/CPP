#include "windows.h"
#include <iostream> 
#include <conio.h>
using namespace std;
struct NUT 
{ 
  char x; 
  NUT *Left,*Right; 
}; 
typedef NUT* Nut; 
char *st="*-96+23"; 
int i=-1; 
char Token;  
Nut Root=NULL;
#ifdef WIN32
void gotoxy(int x, int y)
{
  COORD cur = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
} 
#else
void gotoxy(int x, int y)
{
  printf("\033[%dG\033[%dd", x+1, y+1);
}
#endif
 
void TaoCay(char *st, Nut &Root) 
{ 
  i++; 
  Token = st[i]; 
  Root = new(NUT); 
  Root->x = Token; 
  if((Token<='9')&&(Token>='0')) 
  { 
    Root->Left = NULL; 
    Root->Right = NULL; 
  } 
  else  //Token is [+,-,*,/] 
    { 
      TaoCay(st,Root->Left); 
      TaoCay(st,Root->Right); 
    } 
} 
void XemCay(Nut Root,int x,int y, int k) 
{ 
  if(Root) 
  { 
    gotoxy(x,y); 
	cout<<Root->x; 
    XemCay(Root->Left,x - k/2,y+2,k-3); 
    XemCay(Root->Right,x + k/2,y+2,k-3); 
  } 
} 
float Value(Nut Root) 
{ 
  switch(Root->x) 
  { 
    case '+':return Value(Root->Left) + Value(Root->Right); 
    case '-':return Value(Root->Left) - Value(Root->Right); 
    case '*':return Value(Root->Left) * Value(Root->Right); 
    case '/':return Value(Root->Left) / Value(Root->Right); 
    default : return Root->x - 48; 
  } 
} 
main() 
{ 
  TaoCay(st,Root); 
  XemCay(Root,40,5,20); 
  getch(); 
  cout<<endl<<Value(Root); 
  return 0;
} 

   
