#include <bits/stdc++.h>
using namespace std;

const int N = 1020;
vector<bool> is_prime(N, true);
vector<int> g[N];

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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  vector<int> primes;
  for (int i = 1; i <= 1015; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  int n; cin >> n;
  int deg = n;
  auto it = lower_bound(primes.begin(), primes.end(), deg);
  int d = *it - deg;
  for (int i = 1; i < n; i++) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }
  g[n].push_back(1);
  g[1].push_back(n);
  for (int i = 1; i + 2 <= n and d > 0; i++) {
    if (g[i].size() == 2 and g[i + 2].size() == 2) {
      g[i].push_back(i + 2);
      g[i + 2].push_back(i);
      d--;
    }
  }
  // cout << d << '\n';
  assert(d == 0);
  set<pair<int, int>> ans;
  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      ans.insert({min(u, v), max(u, v)});
    }
  }
  cout << ans.size() << '\n';
  for (auto [u, v] : ans) {
    cout << u << ' ' << v << '\n';
  }

  return 0;
}