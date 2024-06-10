#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int a, b, g; cin >> a >> b >> g;
  int g1 = __gcd(a, g);
  int g2 = __gcd(b, g);
  int c = g / g1;
  int d = g / g2;
  int gg = __gcd((a * c), (b * d));
  if (g != gg) {
    cout << -1 << '\n';
    return;
  }
  cout << c << ' ' << d << '\n';
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