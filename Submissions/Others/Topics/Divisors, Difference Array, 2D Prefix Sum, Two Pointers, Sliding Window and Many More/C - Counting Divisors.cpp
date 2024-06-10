#include <bits/stdc++.h>
using namespace std;

int divisor(int n) {
  int cnt = 0;
  for (int i = 1; 1ll * i * i <= n; i++) {
    if (n % i == 0) {
      cnt++;
      if (n / i != i) cnt++;
    }
  }
  return cnt;
}

void solve() {
  int n; cin >> n;
  cout << divisor(n) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}