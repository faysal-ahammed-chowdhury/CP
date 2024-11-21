#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
void CLEAR(int &N, int pos) { (N &= ~(1 << pos)); }

void solve() {
  int n, k; cin >> n >> k;
  if (n == 1) {
    cout << k << '\n';
    return;
  }

  if (k == 1) {
    for (int i = 1; i <= n; i++) {
      cout << 1 << ' ';
    }
    cout << '\n';
    return;
  }

  if (k == 2) {
    cout << 2 << ' ';
    for (int i = 2; i <= n; i++) {
      cout << 1 << ' ';
    }
    cout << '\n';
    return;
  }

  int msb = __lg(k);
  int a[n + 1];
  a[1] = k;
  a[2] = 0;
  for (int b = 0; b < msb; b++) {
    if (!CHECK(k, b)) {
      SET(a[2], b);
    }
  }
  int xr = 0;
  if (CHECK(a[1], 0)) {
    SET(a[2], 0);
    CLEAR(a[1], 0);
  }
  xr ^= a[1];
  xr ^= a[2];
  for (int i = 3; i <= n; i++) {
    a[i] = 1;
    xr ^= a[i];
  }

  if (xr != ((1 << (msb + 1)) - 1)) {
    if (a[1] + 1 <= k) SET(a[1], 0);
    else {
      CLEAR(a[n], 0);
      for (int b = 0; b < msb; b++) {
        if (CHECK(a[n], b) == CHECK(a[n - 1], b) and !CHECK(a[n], b)) {
          SET(a[n], b);
          SET(a[n - 1], b);
          break;
        }
      }
    }
  }

  if (n == 3) {
    int cur = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      cur ^= a[i];
      ok &= a[i] > 0;
    }
    if (cur != (1 << (msb + 1)) - 1 or !ok) {
      for (int b = 0; b < 30; b++) {
        if (CHECK(a[2], b)) {
          CLEAR(a[2], b);
          SET(a[3], b);
          break;
        }
      }
    }
  }

  xr = 0;
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
    xr ^= a[i];
    assert(a[i] > 0);
  }
  cout << '\n';
  assert(xr == (1 << (msb + 1)) - 1);
  // cout << xr << '\n';
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