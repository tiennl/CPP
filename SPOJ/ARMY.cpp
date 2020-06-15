#include <iostream>
using namespace std;
main(){
	int test,maxG=0,maxMG=0,strengths,G,MG;
	cin>>test;
	for (int i=0;i<test;i++){
		maxG=0;
		maxMG=0;
		cin>>G>>MG;
		for (int j=0;j<G;j++){
			cin>>strengths;
			if (strengths>maxG) maxG=strengths;
		} 
		for (int j=0;j<MG;j++){
			cin>>strengths;
			if (strengths>maxMG) maxMG=strengths;
		} 
		if (maxG>=maxMG) cout<<"Godzilla"<<endl;
		else cout<<"MechaGodzilla"<<endl;
	}
}
