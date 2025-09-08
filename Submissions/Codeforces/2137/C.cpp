#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll a, b; cin >> a >> b;

  if (a % 2 == 0 and b % 2 == 1) {
    cout << -1 << '\n';
    return;
  }

  bool ok = false;
  if (b % 2 == 0) ok = true;

  a *= b;
  b /= b;
  if (ok) {
    a /= 2;
    b *= 2;
  }

  ll sum = a + b;

  if (sum % 2 == 0) cout << sum << '\n';
  else cout << -1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}