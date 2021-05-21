#include <iostream>
#include <vector>
#include <cmath>

void computePrimes(std::vector<int64_t> &primes, int64_t N)
{
  bool *sieve = new bool[N+1];
  for(int i=0; i<N+1; i++)
    sieve[i] = false;

  for(int64_t i=2; i<= N; i++)
  {
    if(sieve[i])
      continue;
    primes.push_back(i);
    for(int64_t j=1; j*i <= N; j++)
      sieve[j*i] = true;
  }
  delete[] sieve;
}

void computeMu(int *result, std::vector<int64_t> &primes, int64_t N)
{
  for(auto p : primes)
  {
    for(int64_t i=1; i*p <= N; i++)
    {
      result[i*p] *= -1;
    }
    int64_t pp = p*p;
    for(int64_t i=1; i*pp <= N; i++)
    {
      result[i*pp] = 0;
    }
  }
}

int main()
{
  int64_t a,b,c,d;
  std::cin >> a >> b >> c >> d;
  int64_t N = std::max(b,d);
  std::vector<int64_t> primes;
  computePrimes(primes, N);
  int *mu = new int[N+1];
  for(int64_t i=0; i<N+1; i++)
    mu[i] = 1;
  computeMu(mu, primes, N);
  int64_t sum = 0;
  for(int64_t i=1; i<=N; i++)
  {
    int64_t term = mu[i] * (b/i - (a-1)/i) * (d/i - (c-1)/i);
//    std::cout << i << " " << term << std::endl;
    sum += term;
  }

  std::cout << sum << std::endl;
  delete[] mu;
}
