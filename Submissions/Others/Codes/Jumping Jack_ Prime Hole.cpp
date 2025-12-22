#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5005, mod = 1e9 + 7;
vector<bool> is_prime(N, true);
vector<int> primes;
int n, m, dp[N];

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

int f(int i) {
  if (i > n) return 1;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = f(i + 1);
  for (auto p : primes) {
    if (p <= m and i + p - 1 <= n) {
      ans += f(i + p + 1);
      ans %= mod;
    }
    else break;
  }

  return ans;
}

void solve() {
  cin >> n >> m;
  m--;
  memset(dp, -1, sizeof dp);
  cout << f(1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  for (int i = 2; i < N; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}