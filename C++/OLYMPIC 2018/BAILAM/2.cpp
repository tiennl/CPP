#include <fstream>
using namespace std;
int tong(int a[],int left,int right)
{
    return left==right ? a[left] : a[left]+tong(a, left+1, right);
}
int main(){
	ifstream fi("bot.inp");
	ofstream fo("bot.out");
    int a[100], n;
    fi>>n;
    for (int i=0;i<n;i++) fi>>a[i];
    int max=a[0],max1;
    int imax=0,jmax=0;
    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++){
            if(i==0 && j==n-1)continue;
            max1=tong(a,i,j);
            if(max1>max){
				max=max1; 
				imax=i; 
				jmax=j;
			}
        }
    fo<<imax+1<<" "<<jmax+1<<" "<< max;
  	fi.close();
  	fo.close();
}
