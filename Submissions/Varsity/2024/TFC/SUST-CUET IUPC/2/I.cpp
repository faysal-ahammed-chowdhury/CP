#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  bool ans = true;
  for (int i = 1; i <= n; i++) {
    ans &= (abs(i - a[i]) % 2 == 0);
  }
  cout << (ans ? "YES\n" : "NO\n");
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}