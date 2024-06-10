#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (is_sorted(a + 1, a + n + 1)) {
    cout << 0 << '\n';
  }
  else if (a[1] == 1 or a[n] == n) {
    cout << 1 << '\n';
  }
  else if (a[1] == n and a[n] == 1) {
    cout << 3 << '\n';
  }
  else {
    cout << 2 << '\n';
  }
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