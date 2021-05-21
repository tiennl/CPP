#include <iostream>
#include <string>

using namespace std;





int main(){
    
    long long MAX = 100000;
    int num;
    cin >> num;
    string numArr = "";
    
    int arr[10]; // mang gom cac chu cai cua so
    
    int inc = 0;
    
    for(int i = 1; i <= MAX; i++){
        
        int k = i;
        
        int subArr[10]; // max la so co 6 chu so
        int subInc = 0;
        while (k > 0) {
            int v = k % 10;
            k /= 10;
            
            subArr[subInc] = v;
            
            subInc++;
        }
        
        for (int j= subInc - 1; j >= 0; j--) {
            numArr += (char)subArr[j];
            //  cout << subArr[j] << endl;
            inc++;
        }
    }
    
    
    // tach cac chu cai cua chu so
    int increase = 0;
    while (num >0) {
        int n = num % 10;
        num /= 10;
        
        arr[increase] = n;
        
        
        increase ++;
        
    }
    
    int arr1[6];
    int increase1 =0;
    
    for (int i = increase -1; i>=0; i--) {
        arr1[increase1] = arr[i];
        increase1++;
    }
    
    
    int vitri = 0;
    
    for (int j=0; j<=inc; j++) {
        // tim vi tri so dau tien xem the nao
        
        
        
        if(arr1[0] == numArr[j]){
            
            // cout << "Debug:" << vitri << endl;
            
            // neu tim thay so dau tien giong ta so sanh tiep tuc cac so con lai
            bool found = true;
            
            for (int i = 1; i< increase1; i++) {
                if(arr1[i] != numArr[j+i]){
                    found = false;
                    break;
                }
            }
            
            if(found){
                // tim thay
                break;
            }
            
        }
        vitri++;
    }
    
    int ketqua = vitri+1;
    cout << ketqua;
    
    
    return 0;
}
