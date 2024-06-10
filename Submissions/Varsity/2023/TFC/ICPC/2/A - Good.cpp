#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e7 + 9;
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

void solve() {
  int n; cin >> n;
  long long g = 0;
  for(int i = 1; i <= n; i++) {
    long long x; cin >> x;
    g = __gcd(g, x);
  }
  for(auto p: primes) {
    if(__gcd(g, 1ll * p) == 1) {
      cout << p << '\n';
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();
  primes.push_back(0);
  for(int i = 2; i < N; i++) {
    if(is_prime[i]) primes.push_back(i);
  }

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}