#include <bits/stdc++.h>
using namespace std;
struct Node{
	string name;
	int marks;
	Node *next;
};
typedef Node* List;
List First;
void InsertLast(List &head, string vname, int vmarks){
	List p,q;
	p=new (Node);
	p->marks=vmarks;
	p->name=vname;
	p->next=NULL;
	if (First==NULL) First=p;
	else{
		q=First;
		while (q->next!=NULL) q=q->next;
		q->next=p;
	}
}
void DeleteFirst(List &head){
	List p=First;
	First=First->next;
	delete(p);
}
void Count(List &head, int marks){
	cout<<"ahihi"<<endl;
}
int main(){
	int m;
	string s,name;
	List First=NULL,Last=NULL;
	while (cin>>s){
		if (s=="fin") return 0;
		else if (s=="ins"){
			cin>>name>>m;
			InsertLast(Last,name,m);
		}
		else if (s=="del"){
			DeleteFirst(First);
		}
		else if (s=="count"){
			cin>>m;
			Count(First,m);
			cout<<endl;
		}
	}
	return 0;
}
