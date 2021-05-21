#include <iostream>

using namespace std;

int uocChung (int a, int b){

	int uc = 1;

	if(a == b || a == 1){
		return 1;
	}

	for (int i = 2; i <= a; ++i)
	{
		if(a % i == 0 && b % i == 0){
			uc = i;

			break;
		}
	}

	 
	return uc;

}

int timViTri(int tu, int mau){
    
    int index = 0;
    int phanTu = 1;
    int phanMau = 2;
    
    while(true){

  
        index++;
        while (uocChung(phanTu, phanMau) > 1) {

 
            phanTu++;

            if(phanTu == tu && phanMau == mau){
            	break;
        	}
        }

        if(phanTu == tu && phanMau == mau){
        
            break;
        }



    
        phanTu++;
        
        if(phanTu == phanMau){
            phanTu = 1;
            phanMau++;
        }
    }
    
    return index;
    
}
int main(){
    
    int tu, mau;
    int t;
    
 
    cin >> t;
    
    int arr[t];
    
    for (int i=0; i< t; i++) {
        
        cin >> tu >> mau;

        int vitri = timViTri(tu, mau);
        
    
        arr[i] = vitri;
    }
    
    
    
    for (int i = 0; i< t; i++){
        
        cout << arr[i] << endl;
    }
    return 0;
}
