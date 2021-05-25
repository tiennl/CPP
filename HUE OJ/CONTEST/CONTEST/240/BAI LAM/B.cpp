#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x;
	Node *next;
};
typedef Node* Tro;
void InsertFirst(int x, Tro &First){
	Tro p,q;
	p=new (Node);
	p->x=x;
	p->next=NULL;
	if (First==NULL) First=p;
	else{
		q=First;
		while (q->next!=NULL) q=q->next;
		q->next=p;
	}
}
int Min(Tro First){
	Tro p=First;
	int mm=p->x;
	while (p!=NULL){
		mm=min(mm,p->x);
		p=p->next;
	}	
	return mm;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	char t;
	int x;
	Tro First=NULL;
	while (cin>>t){
		if (t=='i'){
			cin>>x;
			InsertFirst(x,First);
		}
		else if (t=='m'){
			cout<<Min(First)<<endl;
		}
		else if (t=='0'){
			cin>>x;
			return 0;
		}
	}
	return 0;
}
