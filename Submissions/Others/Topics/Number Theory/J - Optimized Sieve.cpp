#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e8 + 9;
vector<bool> is_prime(N, true);

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
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  vector<int> primes;
  for(int i = 1; i <= N; i++) {
    if(is_prime[i]) {
     primes.push_back(i);
    }
  }
  int n = (int)primes.size();
  for(int i = 0; i < n; i += 100) {
    cout << primes[i] << '\n';
  }
        
  return 0;
}