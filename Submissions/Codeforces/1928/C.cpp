#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  int y = n - x;
  int z = (x >= 2 ? n + abs(2 - x) : 0);

  set<int> se;

  int lim = sqrt(y + 1);
  for (int i = 1; i <= lim; i++) {
    if (y % i == 0) {
      if (i % 2 == 0) {
        if ((i + 2) / 2 > 1 and ((i + 2) / 2 >= x)) {
          se.insert((i + 2) / 2);
        }
      }
      if (i != (y / i)) {
        if ((y / i) % 2 == 0) {
          if (((y / i) + 2) / 2 > 1 and (((y / i) + 2) / 2 >= x)) {
            se.insert(((y / i) + 2) / 2);
          }
        }
      }
    }
  }


  lim = sqrt(z + 1);
  for (int i = 1; i <= lim; i++) {
    if (z % i == 0) {
      if (i % 2 == 0) {
        if ((i + 2) / 2 > 1 and ((i + 2) / 2 >= x)) {
          se.insert((i + 2) / 2);
        }
      }
      if (i != (z / i)) {
        if ((z / i) % 2 == 0) {
          if (((z / i) + 2) / 2 > 1 and (((z / i) + 2) / 2 >= x)) {
            se.insert(((z / i) + 2) / 2);
          }
        }
      }
    }
  }

  cout << (int)se.size() << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}