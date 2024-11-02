#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  for (int a = 1; a <= 50; a++) {
    int b = n - a - 1, c = 1;
    if (a + c + b == n and __gcd(a, b) == c and a != c and c != b and a != b) {
      cout << a << ' ' << b << ' ' << c << '\n';
      return;
    }
  }
  assert(false);
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