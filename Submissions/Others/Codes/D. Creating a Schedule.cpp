#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[m + 1];
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + m + 1);

  int ans[n + 1][7];
  int l = 1, r = m;
  for (int i = 1; i + 1 <= n; i += 2) {
    ans[i][1] = a[l++];
    ans[i + 1][1] = a[r--];
  }

  if (n & 1) {
    ans[n][1] = a[l];
  }

  for (int j = 2; j <= 6; j++) {
    if ((n & 1)) {
      if (j & 1) ans[n][j] = a[l];
      else ans[n][j] = a[r];
    }
    for (int i = 1; i + 1 <= n; i += 2) {
      ans[i][j] = ans[i + 1][j - 1];
      ans[i + 1][j] = ans[i][j - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
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