#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, x, y;
char a[N][N];
string s;
set<pair<int, int>> se;

bool valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  cin >> s;

  if (a[x][y] == '@') se.insert({x, y});
  for (auto c : s) {
    if (c == 'U') {
      if (valid(x - 1, y) and a[x - 1][y] != '#') {
        x -= 1;
        if (a[x][y] == '@') se.insert({x, y});
      }
    }
    else if (c == 'D') {
      if (valid(x + 1, y) and a[x + 1][y] != '#') {
        x += 1;
        if (a[x][y] == '@') se.insert({x, y});
      }
    }
    else if (c == 'L') {
      if (valid(x, y - 1) and a[x][y - 1] != '#') {
        y -= 1;
        if (a[x][y] == '@') se.insert({x, y});
      }
    }
    else {
      if (valid(x, y + 1) and a[x][y + 1] != '#') {
        y += 1;
        if (a[x][y] == '@') se.insert({x, y});
      }
    }
  }

  cout << x << ' ' << y << ' ' << se.size() << '\n';

  return 0;
}