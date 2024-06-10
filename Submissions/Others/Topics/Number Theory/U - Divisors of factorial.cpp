#include <bits/stdc++.h>
using namespace std;

const int N = 50009, mod = 1e9 + 7;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for(int i = 2; i <= lim; i++) {
    if(is_prime[i]) {
      for(int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for(int i = 2; i < N; i++) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int number_of_divisors = 1;
    for(auto p: primes) {
      if(n / p == 0) break;
      int x = n, ex = 0;
      while(x > 1) {
        ex += (x / p);
        x /= p;
      }
      number_of_divisors = 1LL * number_of_divisors * (ex + 1) % mod;
    }

    cout << number_of_divisors << '\n';
  }


  return 0;
}
