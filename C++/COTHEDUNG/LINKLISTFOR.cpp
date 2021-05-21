
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> myList;
    int n; // size of list
    cout<<"Size: " ;
    cin>>n ;
    // create list
    int tempNumber  ;
    for(int i = 0 ; i<n; i++) {
        cin>>tempNumber ;
        myList.push_back(tempNumber ) ;
    }
    // print list
    list<int>::iterator it  ;
    for( it = myList.begin() ; it!=myList.end(); it++) {
       cout<<*it<<" " ;
    }
 
    return 0;
}
