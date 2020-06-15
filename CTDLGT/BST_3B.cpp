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
int Tong(BST Root){
	int s=0;
	if (Root==NULL) return 0;
	if (Root!=NULL){
		s+=Root->x;
		if (Root->Left!=NULL) s+=Tong(Root->Left);
		if (Root->Right!=NULL) s+=Tong(Root->Right);
	}
	return s;
}
int DemLa(BST Root){
	int dem=0;
	if (Root==NULL) return 0;
	if (Root->Left==NULL && Root->Right==NULL) dem++;
	else{
		if (Root->Left!=NULL) dem+=DemLa(Root->Left);
		if (Root->Right!=NULL) dem+=DemLa(Root->Right);
	}
	return dem;
}
int ChieuCao(BST Root){
	int hl=1,hr=1;
	if (Root==NULL) return 0;
	if (Root!=NULL){
		if (Root->Left!=NULL) hl+=ChieuCao(Root->Left);
		if (Root->Right!=NULL) hr+=ChieuCao(Root->Right);
	}
	return max(hl,hr);
}
int main(){
	int x;
	BST Root;
	Nhap(Root);
	cout<<endl<<"Tong cac nut: "<<Tong(Root);
	cout<<endl<<"So nut la: "<<DemLa(Root);
	cout<<endl<<"Chieu cao: "<<ChieuCao(Root);
	return 0;
}
