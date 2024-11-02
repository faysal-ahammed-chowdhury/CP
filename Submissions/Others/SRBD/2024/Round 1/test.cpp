#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    if (__gcd(i, n) == m) {
      cout << i << '\n';
    }
  }

  return 0;
}