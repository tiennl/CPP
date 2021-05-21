#include <iostream>
using namespace std;
char a[10000][10000];
main(){
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++) cin>>a[i][j];
	int kt,den,trang;
	kt=0;
	for (int i=0;i<4;i++){
		if (kt==1) break;
		for (int j=0;j<4;j++){
			den=0;
			trang=0;
			if (a[i][j]=='#') den++; else trang++;
			if (a[i][j+1]=='#') den++; else trang++;
			if (a[i+1][j]=='#') den++; else trang++;
			if (a[i+1][j+1]=='#') den++; else trang++;
			if (trang<=1 || den<=1){
				cout<<"YES";
				kt=1;
				break;
			}
		}
	} 
	
	//if (kt==0) cout<<"NO";
}
