/*
  [NWERC'09] Common substring elimination
  by: Jan Kuipers
*/

#include <vector>
#include <iostream>
#include <map>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

map<pair<string,pair<int,int> >,int> s2i;
vector<pair<string,pair<int,int> > > i2s;
string in;
int i,n;

pair<int,rope<char> > go () {

  pair<string,pair<int,int> > s(make_pair("",make_pair(-1,-1)));
  while (isalpha(in[i])) s.first+=in[i++];

  int nn=n++;
  i2s.push_back(s);

  rope<char> r1,r2;
  
  if (in[i]=='(') {
    i++;
    pair<int,rope<char> > tmp = go();
    s.second.first=tmp.first;
    r1 = tmp.second;
    i++;
    tmp = go();
    s.second.second=tmp.first;
    r2 = tmp.second;
    i++;
  }

  rope<char> r;
  
  if (!s2i.count(s)) {
    s2i[s] = nn;
    i2s[nn] = s;
    r = s.first.c_str();
    if (s.second.first!=-1)
      r = r + '(' + r1 + ',' + r2 + ')';
  }
  else {
    n--;
    i2s.pop_back();
    char tmp[10];
    sprintf (tmp,"%d",s2i[s]+1);
    r = tmp;
  }

  return make_pair(s2i[s],r);  
}

int main () {

  int runs;
  cin>>runs;
  
  while (runs--) {

    s2i.clear();
    i2s.clear();
    
    cin>>in;
    i=n=0;
    cout << go().second << endl;
  }
  
  return 0;
}
