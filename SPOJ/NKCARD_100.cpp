#include <iostream>
#include <vector>


using namespace std;

struct Num{
    int value;
    bool deleted;
    
    
};

vector<int> v;

void AddNum(int n){
    v.push_back(n);
}


int findFirstIndex(int min){
    int index = -1;
    
    int increase = 0;
    
    for (int i = 0; i < v.size(); i++) {
        
        if(v[i] != -1 && increase >= min){
            index = i;
            
            break;
        }
        if(v[i] != -1){
            increase ++;
        }
        
        
    }
    
    return index;
    
}

int main(){
    
    
    
    int m,k;
    string s;
    
     cin >> m >> k;
     getline(cin, s, '.');
    
     /*s = "ABBABA";
     m = 6;
     k = 3;*/
    
    
    
    
    for (int i = 0; i < m; i ++) {
        AddNum(i);
    }
    
    
    int index = 0;
    int secondIndex = 1;
    
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == 65){
        
            AddNum(v[index]);
            v[index] = -1;
            
            
            if( (index+1 < s.size()) && v[index+1] == -1){
                index = secondIndex;
                secondIndex++;
            }else{
                
                 index ++;
                 secondIndex++;
            }
            
            
        }
        if(s[i] == 66){
          
            AddNum(v[secondIndex]);
            
            v[secondIndex] = -1;

            secondIndex++;
        }
    }
    

    
    // tim K
    
    int vitri = 0;
    
    for (int i = k-1; i <= k+1; i++){
        vitri = findFirstIndex(i);
        if(i != k -1){
            cout << " ";
        }
        cout << v[vitri];
        
    }
    
    
    
    return 0;
}
