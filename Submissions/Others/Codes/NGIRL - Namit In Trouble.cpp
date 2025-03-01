#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void solve() {
  ll n, k; cin >> n >> k;
  int ans1 = 0, ans2 = 0;
  for (auto p : primes) {
    ll num = 1ll * p * p;
    if (num <= n) {
      ans1++;
      if (num > k) ans2++;
    }
  }

  cout << ans1 << ' ' << ans2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  for (int i = 2; i < N; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}