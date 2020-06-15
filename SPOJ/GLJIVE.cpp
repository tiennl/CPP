#include <iostream>
using namespace std;
int point[10];
main(){
	int sum1=0,sum2=0;
	for (int i=0;i<10;i++) cin>>point[i];
	for (int i=0;i<10;i++){
		sum2+=point[i];
		if (sum2==100 || (sum2<100 && i==9)){
			cout<<sum2;
			break;
		}
		else if (sum2>100){
			sum1=sum2-point[i];
			if (100-sum1<sum2-100){
				cout<<sum1;
				break;
			}
			else{
				cout<<sum2;
				break;
			}
		}
	}
}
