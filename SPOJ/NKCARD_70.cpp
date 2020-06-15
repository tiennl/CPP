#include <iostream>
#include <vector>


using namespace std;

struct Num{
    
    int value;
    int index;
    bool deleted;
    
    
};

vector<Num> v;

void AddNum(int value, int index){
    Num n{value, index, false};
    v.push_back(n);
}

void Change(Num *a, Num *b){
    a->index = b->index;
}

int findFirstIndex(int min){
    int index = -1;
    
    int increase = 0;
    
    for (int i = 0; i < v.size(); i++) {
        
        
        
        if(v[i].deleted == false && increase >= min){
            index = i;
            
            break;
        }
        
        if(v[i].deleted == false){
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
    


    for (int i = 0; i < m; i ++) {
        AddNum(i, i);
    }
    

    int index = 0;
    
    
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == 65){
            // move from 0 -> last
            index = findFirstIndex(0);
            Num *n = &v[index];
            n->deleted = true;
           
            AddNum(n->value, int(s.size()));
            
        }
        if(s[i] == 66){
            index = findFirstIndex(1);
            Num *n = &v[index];
            n->deleted = true;
            
            AddNum(n->value, int(s.size()));
            
            
        }
    }
    
    
    
    // tim K
    
    int vitri = 0;
    
    for (int i = k-1; i <= k+1; i++){
        vitri = findFirstIndex(i);
        if(i != k -1){
            cout << " ";
        }
        cout << v[vitri].value;
        
    }
    
    
    
    return 0;
}
