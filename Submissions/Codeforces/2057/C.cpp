#include <bits/stdc++.h>
using namespace std;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLR(int &N, int pos) { (N &= ~(1ll << pos)); }

void solve() {
  int l, r; cin >> l >> r;

  int a = -1, b = -1, c = -1, x = 0;
  for (int k = 30; k >= 0; k--) {
    if (CHECK(l, k) == CHECK(r, k)) {
      if (CHECK(l, k)) x |= 1 << k;
      CLR(l, k);
      CLR(r, k);
    }
    else break;
  }

  if (r - l + 1 <= 10) {
    int mx = -1, a, b, c;
    for (int i = l; i <= r; i++) {
      for (int j = i + 1; j <= r; j++) {
        for (int k = j + 1; k <= r; k++) {
          int here = (i ^ j) + (j ^ k) + (k ^ i);
          if (here > mx) {
            mx = here;
            a = i, b = j, c = k;
          }
        }
      }
    }
    a |= x, b |= x, c |= x;
    cout << a << ' ' << b << ' ' << c << '\n';
    // cout << mx << '\n';
    assert(a >= 0 and b >= 0 and c >= 0);
    assert(a != b and a != c and a != c);
    return;
  }

  int msb = __lg(r);
  // cout << msb << '\n';
  a = 1 << msb;
  b = a - 1;
  c = b - 1;
  if (c < l) c = a + 1;
  assert(c >= 0);
  int here1 = (a ^ b) + (b ^ c) + (c ^ a);
  a |= x, b |= x, c |= x;
  int here2 = (a ^ b) + (b ^ c) + (c ^ a);
  cout << a << ' ' << b << ' ' << c << '\n';
  // cout << here2 << '\n';
  assert(here1 == here2);
  assert(a >= 0 and b >= 0 and c >= 0);
  assert(a != b and a != c and a != c);
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