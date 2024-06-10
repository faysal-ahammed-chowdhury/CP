#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n; cin >> n;
  ll a = 1, b = n;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0 and __gcd(1ll * i, n / i) == 1) {
      a = i, b = n / i;
    }
  }
  cout << a << ' ' << b << '\n';

  return 0;
}