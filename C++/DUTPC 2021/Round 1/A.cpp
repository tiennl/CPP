#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

char a[1000][1000];

void createVigenereTable(){
	for (int i='A';i<='Z';i++) a['A'-1][i]=char(i);
	for (int i='A';i<='Z';i++) a[i]['A'-1]=char(i);
	for (int i='A';i<='Z';i++){
		char tmp=char(i);
		for (int j='A';j<='Z';j++){
			a[i][j]=tmp;
			if (tmp>'Z') a[i][j]='A',tmp='A';
			tmp++;
		}
	}
}

int main(){
	FIO
	int t;
	string res="",c,k;
	createVigenereTable();
	cin>>c>>k;
	while (k.size()<c.size()) k+=k;
	createVigenereTable();	
//	for (int i='A'-1;i<='Z';i++){
//		for (int j='A'-1;j<='Z';j++) cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
	for (int i=0;i<c.size();i++){
		for (int j='A';j<='Z';j++)
			if (a[k[i]][j]==c[i]){
				res+=char(j);
				break;
			}
	}	
	cout<<res;
	return 0;
}

//WSAYJSEFMBFQMRRXIPC










