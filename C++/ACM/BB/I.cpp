using namespace std;
#include<bits/stdc++.h>
typedef  long long  ll;
typedef pair<ll,ll> P;
#define F(i,n) for (int  i=0; i<n; i++)
#define Fup(i,x,y) for (int  i=x; i<=y; i++)
#define Fdown(i, y, x) for (int  i=y; i>=x; i--)
#define Ffree(i, x, y , d) for (int i=x; i<=y; i+=d)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define s_time clock_t time_start = clock()
#define t_time cout << double(clock() - time_start) / 1000 << endl
#define fi first
#define se second
ll const MAX = 1000000;
struct Node{
	ll R, G, B;
	Node(ll xx, ll yy, ll zz){
		R = xx;
		G = yy;
		B =zz;
	}
};
ll x,y, z;
Node BK(ll n){
	if (n==1){
		return {x, y, z};	
	}
	if (n%3==2){
		Node k = BK( (n+1)/3);
		return {k.R + k.G, k.B, k.G};
	} 
	Node k = BK(n/3);
	if (n%3){
		return {k.G, k.R, k.B + k.R};
	}
	return {k.B, k.G + k.B, k.R };
}
int main(){
//	freopen("main.txt","r",stdin);
	ll n;
	cin >> x >> y >> z;
	cin >> n;
	Node j = BK(n);
	cout << j.R << " " << j.G << " " << j.B;
		
}






