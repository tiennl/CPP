#include <iostream>
#include <set>
int main()
{
  int L, H;
  std::cin >> L >> H;
  int cnt = 0;
  for(int i=L; i<=H; i++)
  {
    std::set<int> digits;
    int tmp = i;
    bool ok = true;
    while(tmp != 0)
    {
      int digit = tmp % 10;
      digits.insert(digit);
      if(digit == 0 || i % digit)
        ok = false;
      tmp /= 10;
    }
    if(digits.size() != 6)
      ok = false;
    if(ok)
      cnt++;
  }
  std::cout << cnt << std::endl;
}
