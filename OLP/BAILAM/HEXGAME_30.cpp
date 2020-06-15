#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
ll a,b=1238004765;
map <ll,bool> visited;
map <ll,int> trace;
queue <ll> q;
string toString(ll a){
    ostringstream o;
    o<<a;
    return o.str();
}
ll toInt(string x){
	ll c=0;
	stringstream str2num(x);
	str2num>>c;
	return c;
}
string change(string a, int k){
	string s=a;
	if (k==1){
		swap(s[3],s[0]);
		swap(s[3],s[1]);
		swap(s[7],s[3]);
		swap(s[7],s[5]);
		swap(s[7],s[8]);
	}
	else{
		swap(s[1],s[4]);
		swap(s[2],s[4]);
		swap(s[4],s[8]);
		swap(s[6],s[8]);
		swap(s[8],s[9]);
	}
	return s;
}
void bfs(){
	ll u,v;
	while (!q.empty()){
		u=q.front();
		q.pop();
		for (int i=1;i<=2;i++){
			ll p=toInt(change(toString(u),i));
			if (!visited[p]){
				v=p;
				visited[v]=true;
				trace[v]=trace[u]+1;
				if (v==b) return;
				q.push(v);
			}
		}
	}
}
int main(){
	FIO
	ll i,num;
	for (int i=1;i<=10;i++){
		cin>>num;
		a=a*10+num;
	}
	q.push(a);
	visited[a]=true;
	trace[a]=0;
	bfs();
	cout<<trace[b];
	return 0;
}
