#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool valid(int m) {
  int h = (m / 60);
  m %= 60;

  h %= 24;
  m %= 60;

  int d2 = h % 10;
  h /= 10;
  int d1 = h % 10;

  int d4 = m % 10;
  m /= 10;
  int d3 = m % 10;

  // cout << d1 << ' ' << d2 << '\n';
  // cout << d3 << ' ' << d4 << '\n';

  int x = d1 * 10 + d3;
  int y = d2 * 10 + d4;

  // cout << x << ' ' << y << '\n';
  return (x <= 23 and y <= 59 and x >= 0 and y >= 0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, m; cin >> h >> m;
  int mins = (h * 60) + m;

  for (int j = 1; j <= 10000; j++, mins++) {
    if (valid(mins)) {
      int m = mins;
      int h = (m / 60);
      m %= 60;

      h %= 24;
      m %= 60;

      cout << h << ' ' << m << '\n';

      return 0;
    }
  }

  return 0;
}