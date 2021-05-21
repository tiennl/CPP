#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std; 

struct suffix 
{ 
    int index; 
    int rank[2];

    bool operator<(const suffix &other) const
    {
        if (rank[0] < other.rank[0])
            return true;
        if (rank[0] > other.rank[0])
            return false;
        return rank[1] < other.rank[1];
    }
}; 

void buildSuffixArray(string &txt, int n, vector<int> &sufarray) 
{ 
    std::vector<suffix> suffixes;
    suffixes.resize(n);

    for (int i = 0; i < n; i++) 
    { 
        suffixes[i].index = i; 
        suffixes[i].rank[0] = txt[i] - 'a'; 
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1; 
    } 

    std::sort(suffixes.begin(), suffixes.end());
    std::vector<int> ind;
    ind.resize(n);

    for (int k = 4; k < 2*n; k = k*2) 
    { 
        int rank = 0; 
        int prev_rank = suffixes[0].rank[0]; 
        suffixes[0].rank[0] = rank; 
        ind[suffixes[0].index] = 0; 

        for (int i = 1; i < n; i++) 
        { 
            if (suffixes[i].rank[0] == prev_rank && 
                suffixes[i].rank[1] == suffixes[i-1].rank[1]) 
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = rank; 
            } 
            else 
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = ++rank; 
            } 
            ind[suffixes[i].index] = i; 
        } 

        for (int i = 0; i < n; i++) 
        { 
            int nextindex = suffixes[i].index + k/2; 
            suffixes[i].rank[1] = (nextindex < n)? 
                suffixes[ind[nextindex]].rank[0]: -1; 
        } 

        std::sort(suffixes.begin(), suffixes.end());
    } 

    sufarray.clear();
    for (int i = 0; i < n; i++) 
        sufarray.push_back(suffixes[i].index); 
} 

void kasai(string &txt, vector<int> &suffixArr, vector<int> &result) 
{ 
    int n = suffixArr.size(); 
    result.resize(n, 0);
    vector<int> invSuff(n, 0); 

    for (int i=0; i < n; i++) 
        invSuff[suffixArr[i]] = i; 

    int k = 0; 

    for (int i=0; i<n; i++) 
    { 
        if (invSuff[i] == n-1) 
        { 
            k = 0; 
            continue; 
        } 

        int j = suffixArr[invSuff[i]+1]; 

        while (i+k<n && j+k<n && txt[i+k]==txt[j+k]) 
            k++; 

        result[invSuff[i]] = k; 
        if (k>0) 
            k--; 
    }    
} 

int main()
{
    std::string s;
    std::cin >> s;
    std::vector<int> sufarray;
    buildSuffixArray(s, s.length(), sufarray);
    std::vector<int> lcp;
    kasai(s, sufarray, lcp);
    int maxlen = -1;
    int maxstr = -1;
    for (int i = 0; i < lcp.size(); i++)
    {
        if (lcp[i] > maxlen)
        {
            maxlen = lcp[i];
            maxstr = i;
        }
    }
    for (int j = 0; j < maxlen; j++)
    {
        std::cout << s[sufarray[maxstr] + j];
    }
    std::cout << std::endl;
}
