#include <bits/stdc++.h>
using namespace std;

int legendre(int n, int p) {
  int ex = 0;
  while (n) {
    ex += (n / p);
    n /= p;
  }
  return ex;
}

int cs;
void solve() {
  int n, r, p, q; cin >> n >> r >> p >> q;
  int two1 = legendre(n, 2);
  int five1 = legendre(n, 5);
  two1 -= legendre(r, 2);
  two1 -= legendre(n - r, 2);
  five1 -= legendre(r, 5);
  five1 -= legendre(n - r, 5);
  int two2 = 0, five2 = 0;
  while (p % 2 == 0) {
    two2++;
    p /= 2;
  }
  while (p % 5 == 0) {
    five2++;
    p /= 5;
  }
  two2 *= q;
  five2 *= q;
  int ans = min(two1 + two2, five1 + five2);
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}