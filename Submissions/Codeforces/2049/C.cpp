#include <bits/stdc++.h>
using namespace std;

int mex(int a, int b) {
  set<int> se;
  se.insert(0);
  se.insert(1);
  se.insert(2);
  se.insert(3);
  se.erase(a);
  se.erase(b);
  return *se.begin();
}

int mex(int a, int b, int c) {
  set<int> se;
  se.insert(0);
  se.insert(1);
  se.insert(2);
  se.insert(3);
  se.insert(4);
  se.erase(a);
  se.erase(b);
  se.erase(c);
  return *se.begin();
}

void solve() {
  int n, x, y; cin >> n >> x >> y;
  int xx = min(x, y), yy = max(x, y);
  x = xx, y = yy;
  int a[n + 1];
  int start = 1;
  if (n % 2 == 1) {
    a[1] = 2;
    start++;
  }

  for (int i = start, j = 1; i <= n; i++, j++) {
    if (j & 1) a[i] = 0;
    else a[i] = 1;
  }

  if (x == y - 1 or (x == 1 and y == n) or a[x] != a[y]) {
    for (int i = 1; i <= n; i++) {
      int prev = i == 1 ? n : i - 1;
      int nxt = i == n ? 1 : i + 1;
      if (i == x) {
        assert(a[i] == mex(a[prev], a[nxt], a[y]));
      }
      else if (i == y) {
        assert(a[i] == mex(a[prev], a[nxt], a[x]));
      }
      else {
        assert(a[i] == mex(a[prev], a[nxt]));
      }
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }

  int here = x == 1 ? n : x - 1;
  int prev = here == 1 ? n : here - 1;
  int nxt = here == n ? 1 : here + 1;
  a[x] = 2;
  a[here] = mex(a[prev], a[nxt]);

  for (int i = 1; i <= n; i++) {
    int prev = i == 1 ? n : i - 1;
    int nxt = i == n ? 1 : i + 1;
    if (i == x) {
      assert(a[i] == mex(a[prev], a[nxt], a[y]));
    }
    else if (i == y) {
      assert(a[i] == mex(a[prev], a[nxt], a[x]));
    }
    else {
      assert(a[i] == mex(a[prev], a[nxt]));
    }
    cout << a[i] << ' ';
  }
  cout << '\n';
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