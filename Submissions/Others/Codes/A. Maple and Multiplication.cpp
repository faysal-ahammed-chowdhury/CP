#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int a, b; cin >> a >>  b;
  int gc = __gcd(a, b);

  a /= gc, b /= gc;

  int ans = 0;
  if (a > 1) ans++;
  if (b > 1) ans++;

  cout << ans << '\n';
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