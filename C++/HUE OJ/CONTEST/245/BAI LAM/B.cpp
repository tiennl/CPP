#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int Data;
	struct Node* pNext;
};
typedef struct Node NODE;
struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;
void Init(LIST &l)
{
  l.pHead = l.pTail = NULL;
}
NODE *GetNode(int x)
{
	NODE *p= new NODE;
	if(p == NULL)
	{
	  return NULL;
    }
    p -> Data = x;
    p -> pNext = NULL;
	return p;
}
void AddHead(LIST &l , NODE *p)
{
	if(l.pHead == NULL)
	{
	  l.pHead = l.pTail = p;
    }
	else
	{
		p-> pNext= l.pHead;
		l.pHead = p;
	}
}
void ChangeList(LIST l)
{
	int s;
    NODE *p=l.pHead;
	s = p->Data;
	for(p=p;p->pNext!=NULL;p=p->pNext)
	{
		cout<<s*p->pNext->Data<<" ";
		s=p->Data;
		
	}
	cout<<s*l.pTail->Data;
}
void Input(LIST &l)
{
  Init(l);
  int n,x;
  cin>>n;
  while(n--){
  cin>>x;
  NODE *p = GetNode(x);
  AddHead(l,p);
  }
  ChangeList(l);
}
int main()
{
       LIST(l);
       l.pHead = l.pTail = NULL;
       Input(l);
       return 0;
}

/*
input: 5
6 5 4 3 2
output: 6 8 15 24 30
*/
