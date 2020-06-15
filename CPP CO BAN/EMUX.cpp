#include<iostream>
#include<iomanip>
using namespace std;
int main(){
  double x,epsilon,ex;
  char ch;
  do{
    cout<<"Nhap x, epsilon: ";
    cin>>x>>epsilon;
    int k=0;
    double so_hang_k=1;
    ex=so_hang_k;
    while(so_hang_k>=epsilon){
      k++;
      so_hang_k=so_hang_k*x/k;
      ex+=so_hang_k;
    }
    cout<<fixed<<setprecision(4);
    cout<<"e^x = "<<ex<<endl;
    cout<<"Co muon tinh tiep tuc e^x cua so khac khong: ";
    cin>>ch;
  }
  while(ch=='c'||ch=='C');
  return 0;
}

