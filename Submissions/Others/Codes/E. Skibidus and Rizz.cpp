#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  if (abs(n - m) > k or k > max(n, m)) {
    cout << -1 << '\n';
    return;
  }

  if (n > m) {
    for (int i = 1; i <= k; i++, n--) {
      cout << "0";
    }
    while (n > 0 and m > 0) {
      cout << "10";
      n--, m--;
    }
    assert(n == 0);
    while (m--) cout << "1";
    cout << '\n';
  }
  else {
    for (int i = 1; i <= k; i++, m--) {
      cout << 1;
    }
    while (n > 0 and m > 0) {
      cout << "01";
      n--, m--;
    }
    assert(m == 0);
    while (n--) cout << "0";
    cout << '\n';
  }
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