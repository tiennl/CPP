#include <iostream>

#define Max 200 
#define true 1 
#define false 0 

using namespace std;

int n; 
int x[Max+1]; 
int a[Max+1]; 
int b[2*Max+1]; 
int c[2*Max];

int  count;  
void Try(int i); 
void output(void); 

void init(){ 
  	int i; 
  	cout<<"n = "; 
  	cin>>n; 
  	for(i=1;i<=n;i++) a[i]=true; 
  	for(i=2;i<=2*n;i++) b[i]=true; 
  	for(i=1;i<=2*n-1;i++) c[i]=true; 
  	count=0; 
}
 
void output() 
{ 
	int i; 
  	count++; 
  	cout<<count; 
  	for(i=1;i<=n;i++) cout<<x[i]<<" "; 
  	cout<<endl;
} 
void Try(int i){ 
  	int j; 
   	for(j=1;j<=n;j++) 
     	if  (a[j] && b[i+j] && c[i-j+n]){  
         	x[i]=j; 
         	a[j]=false; 
			b[i+j]=false; 
			c[i-j+n]=false; 
         	if (i==n) output();
  			else Try(i+1); 
         	a[j]=true; 
			b[i+j]=true; 
			c[i-j+n]=true; 
      	} 
} 
int main() 
{ 
  	init(); 
   	Try(1); 
} 
        
