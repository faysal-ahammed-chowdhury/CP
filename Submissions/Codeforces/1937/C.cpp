#include <bits/stdc++.h>
using namespace std;

char query(int a, int b, int c, int d) {
  cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
  char sign; cin >> sign;
  return sign;
}

void solve() {
  int n; cin >> n;
  int a = 0;
  for (int i = 1; i < n; i++) {
    char sign = query(a, a, i, i);
    if (sign == '<') {
      a = i;
    }
  }

  int x = a, y = a;
  for (int i = 0; i < n; i++) {
    char sign = query(x, y, x, i);
    if (sign == '<') {
      y = i;
    }
    else if (sign == '=') {
      sign = query(y, y, i, i);
      if (sign == '>') {
        y = i;
      }
    }
  }

  cout << "! " << x << ' ' << y << endl;
}

int32_t main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}