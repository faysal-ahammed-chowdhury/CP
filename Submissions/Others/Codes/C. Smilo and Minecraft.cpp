#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 505;
int prefix[N][N];

int query(int x1, int y1, int x2, int y2) {
  return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
}

void solve() {
  int n, m, k; cin >> n >> m >> k;
  string s[n + 1];
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (auto c : s[i]) {
      cnt += c == 'g';
    }
    s[i] = "." + s[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (s[i][j] == 'g');
    }
  }

  int mn = 1e6;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] != '.') continue;
      int x1 = i - (k - 1);
      int y1 = j - (k - 1);
      int x2 = i + (k - 1);
      int y2 = j + (k - 1);
      x1 = max(x1, 1);
      y1 = max(y1, 1);
      x2 = min(x2, n);
      y2 = min(y2, m);
      mn = min(mn, query(x1, y1, x2, y2));
      // cout << i << ' ' << j << ": ";
      // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << query(x1, y1, x2, y2) << '\n';
    }
  }

  int ans = cnt - mn;
  if (mn == 1e6) ans = 0;
  cout << ans << '\n';
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