#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll __lcm(ll a, ll b) {
  return (a * b) / __gcd(a, b);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll ans = 1;
  int st = max(1, n - 50);
  for (int i = st; i <= n; i++) {
    for (int j = st; j <= n; j++) {
      for (int k = st; k <= n; k++) {
        ans = max(ans, __lcm(i, __lcm(j, k)));
      }
    }
  }

  cout << ans << '\n';

  return 0;
}