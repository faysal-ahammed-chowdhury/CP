#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool is_prime(int n) {
  if (n == 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  int n; cin >> n;

  ll ans = 1ll * n * (n - 1);
  if (is_prime(n)) {
    cout << ans << '\n';
    return;
  }

  int x = n;

  vector<int> divisors;
  for (int i = 2; 1ll * i * i <= x; i++) {
    if (x % i == 0) {
      divisors.push_back(i);
      if (i != (x / i)) {
        divisors.push_back(x / i);
      }
    }
  }
  divisors.push_back(n);
  sort(divisors.begin(), divisors.end());

  for (auto x : divisors) {
    if ((1ll * n * x) % (n + x) == 0) {
      ans = min(ans, 1ll * x);
    }
  }

  int sz = divisors.size();
  for (int i = 0; i < sz - 1; i++) {
    ll x = 1ll * divisors[sz - i - 2] * (divisors[i + 1] - divisors[i]);
    ans = min(ans, x);
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}