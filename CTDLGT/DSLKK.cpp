#include <iostream>
#include <conio.h>
using namespace std;
struct NUT{
	int Data;
	NUT *Prev, *Next;
};
typedef NUT* Tro;
void LastInsert(int x, Tro &First, Tro &Last){
	Tro p=new(NUT);
	p->Data=x;
	p->Next=NULL;
	p->Prev=NULL;
	if (First==NULL) First=Last=p;
	else{
		Last->Next=p;
		p->Prev=Last;
		Last=p;
	}
}
void Nhap(Tro &First, Tro &Last){
	int x;
	char ch;
	do{
		cout<<endl<<"Nhap x = ";
		cin>>x;
		LastInsert(x,First,Last);
		cout<<"Nhan <ESC> de ket thuc nhap!";
		ch=getch();
	}
	while (ch!=27);
}
void Xem(Tro First){
	cout<<endl;
	Tro p = First;
	while (p){
		cout<<p->Data<<" ";
		p = p->Next;
	}
}
bool Doixung(Tro First, Tro Last){
	if (First==Last) return true;
	else if (First->Data!=Last->Data) return false;
	else return Doixung(First->Next,Last->Prev);
}
void Insert(int x, Tro q, Tro &First, Tro &Last){
	// B1 Tao nut moi p cho x
	Tro p=new(NUT);
	p->Data=x;
	// B2 Bo sung sau q
	p->Next=q->Next;
	p->Prev=q;
	q->Next->Prev=p;
	q->Next=p;
}
void FirstDel(Tro &First, Tro &Last){
	// Dinh vi den nut can xoa p
	Tro p=First;
	if (First==Last) 	// danh sach chi co nut
		First=Last=NULL;
	else {
		First=p->Next;
		First->Prev=NULL;
	}
	delete p;
}
void Delete(Tro q, Tro &First, Tro &Last){
	// Xoa nut sau q
	Tro p=q->Next;
	q->Next=p->Next;	// 1
	p->Next->Prev=q;	// 2
	delete p;
}
int main(){
	Tro First=NULL,Last=NULL;
	Nhap(First,Last);
	Xem(First);
	int x=1000;
	Tro q=First->Next;
/*	Insert(x,q,First,Last);
	Xem(First);
	*/
/*	FirstDel(First,Last);
	Xem(First);
	*/
/*	if (Doixung(First,Last)) cout<<endl<<"Danh sach doi xung";
	else cout<<endl<<"Danh sach khong doi xung";
	*/
	Delete(q,First,Last);
	Xem(First);
	return 0;
}
