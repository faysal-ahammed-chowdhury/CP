#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> primes;

bool is_prime(int n) {
  if (n == 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void prec() {
  for (int i = 1; i <= 50; i++) {
    if (is_prime(i)) primes.push_back(i);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int sz = primes.size();

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll ans = 1e18;

  for (int mask = 0; mask < (1 << sz); mask++) {
    ll y = 1;
    for (int k = 0; k < sz; k++) {
      if (mask & (1 << k)) {
        y *= primes[k];
      }
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      ok &= __gcd(1ll * a[i], y) > 1;
    }
    if (ok) ans = min(ans, y);
  }

  cout << ans << '\n';

  return 0;
}