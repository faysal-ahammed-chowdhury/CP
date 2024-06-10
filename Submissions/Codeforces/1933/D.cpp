#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt += a[i] == 1;
  }
  if (cnt == 2) {
    cout << "NO\n";
    return;
  }

  sort(a + 1, a + n + 1);
  if (a[1] != a[2]) {
    cout << "YES\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] % a[1] > 0) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
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