#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;
int a[N][N];
long long d[N][N]; // difference array

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c; cin >> c;
      a[i][j] = c - '0';
    }
  }

  int q; cin >> q;
  while (q--) {
    int x1, y1, x2, y2, x; cin >> x1 >> y1 >> x2 >> y2;
    x = 1;
    d[x1][y1] += x;
    d[x1][y2 + 1] -= x;
    d[x2 + 1][y1] -= x;
    d[x2 + 1][y2 + 1] += x;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
    }
  }

  // new updated array
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << (d[i][j] + a[i][j]) % 2;
    }
    cout << '\n';
  }

  return 0;
}