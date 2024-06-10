#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 50000 + 9;
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
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  sieve();
  for(int i = 2; i < N; i++) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    map<int, int> mp;
    for(auto p: primes) {
      if(p > n) break;
      int x = n;
      int power = 0;
      while(x) {
        power += (x / p);
        x /= p;
      }
      mp[p] = power;
    }

    long long ans = 1;
    for(auto i: mp) {
      ans = 1ll * ans * (i.second + 1);
      ans %= mod;
    }
    cout << ans << '\n';
  }

  return 0;
}