#include <bits/stdc++.h>
using namespace std;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

const int N = 105, inf = 2e9;
int n, m, a[N][N];

int get(int i, int j) {
  int mx = 0;
  bool ok = true;
  for (int k = 0; k < 4; k++) {
    int new_i = i + dx[k];
    int new_j = j + dy[k];
    if (new_i >= 1 and new_i <= n and new_j >= 1 and new_j <= m) {
      ok &= a[new_i][new_j] < a[i][j];
      mx = max(mx, a[new_i][new_j]);
    }
  }
  if (ok) return mx;
  else return inf;
};

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  while (true) {
    bool stop = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int x = get(i, j);
        if (x != inf and x < a[i][j]) {
          a[i][j] = x;
          stop = false;
        }
      }
    }
    if (stop) break;
    break;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i][j] << ' ';
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