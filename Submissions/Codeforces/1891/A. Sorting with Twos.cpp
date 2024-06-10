#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int x = __lg(n);
  x = 1 << x;
  vector<int> v;
  for (int i = 1; i + 1 <= n; i++) {
    if (a[i] > a[i + 1]) {
      v.push_back(i);
    }
  }
  for (auto i: v) {
    if (i > x or (i & (i - 1)) != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}