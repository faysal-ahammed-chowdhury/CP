#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  string s[n], ans[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    ans[i] = s[i];
  }

  string a[2] = {"WB", "BW"};
  for (int j = 0; j < m; j++) {
    int cur = 0, cnt = 0;;
    for (int i = 0; i < n; i++) {
      if (s[i][j] == 'L') {
        cnt++;
        ans[i][j] = a[cur][0];
        ans[i][j + 1] = a[cur][1];
        cur ^= 1;
      }
    }
    if (cnt & 1) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int i = 0; i < n; i++) {
    int cur = 0, cnt = 0;;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'U') {
        cnt++;
        ans[i][j] = a[cur][0];
        ans[i + 1][j] = a[cur][1];
        cur ^= 1;
      }
    }
    if (cnt & 1) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
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