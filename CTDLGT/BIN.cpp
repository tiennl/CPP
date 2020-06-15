#include <iostream>
using namespace std;
struct NUT{
	int Data;
	NUT *next;
};
typedef NUT* Tro;
void PUSH(int x, Tro &Stack){
	Tro p=new (NUT);
	p->Data=x;
	p->next=Stack;
	Stack=p;
}
int POP(Tro &Stack){
	Tro p=Stack;
	Stack=Stack->next;
	int x=p->Data;
	delete(p);
	return x;
}
void Bin(int n){
	Tro Stack=NULL;
	while (n>0){
		PUSH(n%2,Stack);
		n/=2;
	}
	while (Stack){
		int x=POP(Stack);
		cout<<x;
	}
}
int main(){
	int n;
	cin>>n;
	Bin(n);
	return 0;
}
