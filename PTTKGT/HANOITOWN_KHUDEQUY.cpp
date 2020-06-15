#include <iostream>
#include <stack>
using namespace std;
struct TrangThai{
	int n;
	char A,B,C;
};
int i=0;
void in(TrangThai tt){
	i++;
	cout<<endl<<i<<".Chuyen dia tu "<<tt.A<<" qua "<<tt.C;
}
void ThapHN(int n, char A, char B, char C){
	if (n>0){
		TrangThai tt={n,A,B,C};
		stack <TrangThai> s;
		s.push(tt);
		while (!s.empty()){
			tt=s.top();
			s.pop();
			if (tt.n==1) in(tt);
			else{
				TrangThai tt3={tt.n-1,tt.B,tt.A,tt.C};
				s.push(tt3);
				TrangThai tt2={1,tt.A,tt.B,tt.C};
				s.push(tt2);
				TrangThai tt1={tt.n-1,tt.A,tt.C,tt.B};
				s.push(tt1);
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	ThapHN(n,'A','B','C');
	return 0;
}
