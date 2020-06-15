#include <bits/stdc++.h>
using namespace std;
struct Congnhan{
	char ten[5];
	int nam_sinh;
	int gio_lam;
};
int main(){
	Congnhan name[5];
	Congnhan year[5];
	Congnhan time[5];
	for (int i=1;i<=5;i++){
		fflush(stdin);
		cin>>name[i].ten;
		cin>>year[i].nam_sinh;
		cin>>time[i].gio_lam;
	}
	time[5].gio_lam--;
	for (int i=1;i<=5;i++)
	//	cout<<name[i].ten<<" "<<year[i].nam_sinh<<" "<<time[i].gio_lam<<endl;
		if (time[i].gio_lam>=40) cout<<name[i].ten<<endl;
	return 0;
}
