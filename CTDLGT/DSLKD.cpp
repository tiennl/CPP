#include <iostream>
#include <conio.h>
using namespace std;
struct NUT{
	int x;
	NUT *next;
};
typedef NUT* Tro; 
void LastInsert(int l, Tro &First){
	Tro p,q;
	p=new NUT;
	p->x=l;
	p->next=NULL;
	if (First==NULL) First=p;
	else{
		q=First;
		while (q->next!=NULL) q=q->next;
		q->next=p;
	}
}
void Nhap(Tro &First){
	int l;
	char ch;
	do{
		cout<<endl;
		cout<<"Nhap x = ";
		cin>>l;
		LastInsert(l,First);
		cout<<"Nhan <ESC> de ket thuc nhap!";
		ch=getch();
	}
	while (ch!=27);
}
void Xem(Tro First){
	cout<<endl;
	Tro p=First;
	while (p!=NULL){
		cout<<p->x<<" ";
		p=p->next;
	}
}
int main(){
	Tro First=NULL;
	Nhap(First);
	Xem(First);
	return 0;
}
