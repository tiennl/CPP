#include<bits/stdc++.h>
using namespace std;
struct so{
	int chuc,donvi;
};
main()
{
	string a,b,kq="";
	cin>>a>>b;
	so demo;
	int phu;
	vector<so > x[b.size()];
	for(int i=0;i<b.size();i++)
	{
		for(int j=0;j<a.size();j++)
		{
			demo.chuc=(b[i]-48)*(a[j]-48);
			demo.donvi=demo.chuc%10;
			demo.chuc=demo.chuc/10;
		x[i].push_back(demo);
		}
		
	}
	int carry=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		int j=b.size()-1,k=i,dem=0;
		int sum=carry;
		while(k<a.size()&&j>=0)
		{
			dem++;
			if(dem%2==1)
			{
				sum+=x[j][k].donvi;
				k++;
			}
			
			else
			{
				sum+=x[j][k].chuc;
				j--;
			}
			
		}
		string tmp="";
		tmp.push_back(sum%10+48);
		kq=tmp+kq;
		carry=sum/10;
	}
	
	for(int i=b.size()-1;i>=0;i--)
	{
		
		int j=0,k=i,dem=0;
		int sum=carry;
		while(j<a.size()&&k>=0)
		{
			dem++;
			if(dem%2==1)
			{
				sum+=x[k][j].chuc;
				k--;
			}
			
			else
			{
				sum+=x[j][k].donvi;
				j++;
			}
			
		}
		string tmp="";
		tmp.push_back(sum%10+48);
		kq=tmp+kq;
		carry=sum/10;
	}
	string tmp="";
	if(carry>0) tmp.push_back(carry+48);
	kq=tmp+kq;
	while(kq[0]=='0'&&kq.size()>1)
	kq.erase(kq.begin());
	cout<<kq;
	return 0;
}
