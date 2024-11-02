#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long p, q, b; cin >> p >> q >> b;
  long long gc = __gcd(p, q);
  q /= gc;
  b = __gcd(q, b);
  while (b != 1) {
    // cout << q << ' ' << b << '\n';
    while (q % b == 0) q /= b;
    b = __gcd(q, b);
  }
  if (q > 1) cout << "Infinite\n";
  else cout << "Finite\n";
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