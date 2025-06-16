#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, x; cin >> n >> x;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) continue;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] == 0) continue;
      if (j - i >= x) {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
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