#include <bits/stdc++.h>
using namespace std;
#define int long long

int l, r, i, k, mod;

int f(int r) {
  if (r % 4 == 3) return 0;
  int cnt = (r % 4) + 1;
  int xr = 0;
  while (cnt--) {
    xr ^= r;
    r--;
  }
  return xr;
}

int get(int r) {
  if (r < k) return 0;
  int cnt = (r - k ) / mod;
  cnt++;
  if (cnt % 4 == 0) return 0;
  int last = k + ((cnt - 1) * mod);
  int xr = 0;
  cnt = (cnt % 4);
  while (cnt--) {
    xr ^= last;
    last -= mod;
  }
  return xr;
}

int fun(int r) {
  return f(r) ^ get(r);
}

void solve() {
  cin >> l >> r >> i >> k;
  mod = (1ll << i);
  cout << (fun(r) ^ fun(l - 1)) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}