#include <iostream>
#include <conio.h>
using namespace std;
struct NUT{
	int x;
	NUT *Left,*Right;
};
typedef NUT* BST;
void Insert(int x, BST &Root){
	if (Root==NULL){
		Root=new (NUT);
		Root->x=x;
		Root->Left=NULL;
		Root->Right=NULL;
	} 
	else if (x<Root->x) Insert(x,Root->Left);
	else if (x>Root->x) Insert(x,Root->Right);
}
void Nhap(BST &Root){
	Root=NULL;
	char ch;
	int x;
	do{
		cout<<endl<<"Nhap x = ";
		cin>>x;
		Insert(x,Root);
		cout<<"Nhan <ESC> de ket thuc nhap";
		ch=getch();
	}
	while (ch!=27);
}
void LNR(BST Root){
	if (Root){
		LNR(Root->Left);
		cout<<Root->x<<" ";
		LNR(Root->Right);
	}
}
BST Search(int x, BST Root){
	if (Root==NULL) return NULL;
	else if (x==Root->x) return Root;
	else if (x<Root->x) return Search(x,Root->Left);
	else return Search(x,Root->Right);
}
int main(){
	int x;
	BST Root;
	Nhap(Root);
	cout<<endl;
	LNR(Root);
	cout<<endl;
	cout<<"Nhap x = ";
	cin>>x;
	if (Search(x,Root)) cout<<x<<" co tren cay BST";
	else cout<<x<<" khong co tren cay BST";
	return 0;
}
