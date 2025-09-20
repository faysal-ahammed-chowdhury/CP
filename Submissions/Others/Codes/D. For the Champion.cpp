#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int inf = 1e9;
// int xx, yy;

int dis(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int query(char c, int k) {
  cout << "? " << c << ' ' << k << endl;
  // if (c == 'U') yy += k;
  // else if (c == 'D') yy -= k;
  // else if (c == 'R') xx += k;
  // else xx -= k;
  int d; cin >> d;
  return d;
}

void solve() {
  int n; cin >> n;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  int x1 = a[1].first, y1 = a[1].second;
  int x2 = a[1].first, y2 = a[1].second;
  for (int i = 1; i <= n; i++) {
    if (dis(a[i].first, a[i].second, inf, -inf) <= dis(x1, y1, inf, -inf)) {
      x1 = a[i].first;
      y1 = a[i].second;
    }
    if (dis(a[i].first, a[i].second, -inf, -inf) <= dis(x2, y2, -inf, -inf)) {
      x2 = a[i].first;
      y2 = a[i].second;
    }
  }

  // xx = 100, yy = 99;
  query('D', inf);
  query('D', inf);
  query('R', inf);
  int d1 = query('R', inf);
  // cout << xx << ' ' << yy << '\n';
  // cout << "Here: " << abs(xx - 0) + abs(yy - 0) << '\n';
  query('L', inf);
  query('L', inf);
  query('L', inf);
  int d2 = query('L', inf);
  // cout << "Yoo: " << d1 << '\n';
  // cout << xx << ' ' << yy << '\n';
  // cout << "Here: " << abs(xx - 0) + abs(yy - 0) << '\n';

  d2 -= y2 - y1;
  y2 = y1;

  int x_plus_xprime = (4 * inf) - abs(x2 - x1);
  // cout << x_plus_xprime << '\n';
  int y = y1 - ((d1 + d2 - x_plus_xprime) / 2);
  int x = (d1 - ((d1 + d2 - x_plus_xprime) / 2)) + x1;
  // cout << x << ' ' << y << '\n';

  x -= 2 * inf;
  y += 2 * inf;

  cout << "! " << x << ' ' << y << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}