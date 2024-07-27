#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int x, y; cin >> x >> y;
  char a[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  string s; cin >> s;
  for (auto c : s) {
    if (c == 'U') {
      if (x - 1 >= 1 and a[x - 1][y] == '.') {
        x--;
      }
    }
    else if (c == 'D') {
      if (x + 1 <= n and a[x + 1][y] == '.') {
        x++;
      }
    }
    else if (c == 'L') {
      if (y - 1 >= 1 and a[x][y - 1] == '.') {
        y--;
      }
    }
    else if (c == 'R') {
      if (y + 1 <= m and a[x][y + 1] == '.') {
        y++;
      }
    }
  }
  cout << x << ' ' << y << '\n';

  return 0;
}