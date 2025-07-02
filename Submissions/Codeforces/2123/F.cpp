#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;
vector<bool> vis(N);

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
  int n; cin >> n;
  int ans[n + 1];
  auto it = upper_bound(primes.begin(), primes.end(), n);
  --it;
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
  }
  while (true) {
    int x = *it;
    vector<int> v;
    for (int j = x; j <= n; j += x) {
      if (!vis[j]) {
        v.push_back(j);
        vis[j] = true;
      }
    }
    for (int j = 0; j + 1 < v.size(); j++) {
      ans[v[j]] = v[j + 1];
    }
    ans[v.back()] = v.front();
    if (it == primes.begin()) break;
    --it;
  }

  ans[1] = 1;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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