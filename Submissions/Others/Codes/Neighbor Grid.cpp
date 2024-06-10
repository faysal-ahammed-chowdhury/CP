#include <bits/stdc++.h>
using namespace std;

int n, m;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

bool ok(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

void solve() {
  cin >> n >> m;
  int a[n + 1][m + 1], ans[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  bool possible = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int mx = 0;
      for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        if (ok(new_i, new_j)) mx++;
      }
      ans[i][j] = mx;
      possible &= a[i][j] <= ans[i][j];
    }
  }

  if (possible) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << ans[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  else {
    cout << "NO\n";
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