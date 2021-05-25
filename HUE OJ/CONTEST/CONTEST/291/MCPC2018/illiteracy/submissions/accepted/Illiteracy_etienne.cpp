#include <iostream>
#include <string>
#include <set>

void rotate(char &c)
{
    if(c=='F')
        c = 'A';
    else
        c++;
}

std::string transform(const std::string &source, int x)
{
    std::string s = source;
    char c = s[x-1];
    switch(c)
    {
        case 'A':
        {
            if(x > 1)
                rotate(s[x-2]);
            if(x < 8)
                rotate(s[x]);
            break;
        }
        case 'B':
        {
            if(x > 1 && x < 8)
                s[x] = s[x-2];
            break;
        }
        case 'C':
        {
            rotate(s[8-x]);
            break;
        }
        case 'D':
        {
            if(x <= 4)
            {
                for(int i=1; i<x; i++)
                {
                    rotate(s[i-1]);
                }
            }
            else
            {
                for(int i=x+1; i<9; i++)
                {
                    rotate(s[i-1]);
                }
            }
            break;
        }
        case 'E':
        {
            if(x > 1 && x < 8)
            {
                int y = std::min(x-1, 8-x);
                rotate(s[x-y-1]);
                rotate(s[x+y-1]);
            }
            break;
        }
        case 'F':
        {
            if(x%2==0)
                rotate(s[x/2-1]);
            else
                rotate(s[(9+x)/2-1]);
            break;
        }
    }
    return s;
}

int hash(const std::string &s)
{
    int ret = 0;
    for(int i=0; i<8; i++)
    {
        ret += s[i]-'A';
        ret *= 6;
    }
    return ret;
}

int main()
{
    std::string source;
    std::string target;
    std::cin >> source >> target;
    std::set<std::string> pool;
    std::set<int> seen;
    pool.insert(source);
    int iter=0;
    while(true)
    {
        if(pool.count(target))
            break;
        std::set<std::string> newpool;
        for(auto &s : pool)
        {
            for(int i=1; i<=8; i++)
            {
                std::string news = transform(s, i);
//                std::cout << news << std::endl;
                int h = hash(news);
                if(!seen.count(h))
                {
                    newpool.insert(news);
                    seen.insert(h);
                }
            }
        }
        pool = newpool;
        iter++;
    }
    std::cout << iter << std::endl;
}
