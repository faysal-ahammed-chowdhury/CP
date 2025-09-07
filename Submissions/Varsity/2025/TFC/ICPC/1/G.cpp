#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int K = 62;
bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

int f(int n) {
  int y = (n + 1) % 4;
  int ans = 0;
  while (y--) {
    ans ^= n;
    n--;
  }
  return ans;
}

void solve() {
  ll l, r; cin >> l >> r;
  int xr = f(r) ^ f(l - 1);
  l++, r++;

  int orr = 0;
  for (int k = 0; k < K; k++) {
    int x = (1ll << k);
    int y = (l + x - 1) / x;

    if (y % 2 == 0) SET(orr, k);
    else {
      int nxt = (x * y) + 1;
      if (r >= nxt) SET(orr, k);
    }
  }

  int nd = 0;
  for (int k = 0; k < K; k++) {
    int x = (1ll << k);
    int y = (l + x - 1) / x;


    if (y % 2 == 0) {
      int nxt = (x * y) + 1;
      if (r < nxt) SET(nd, k);
    }
  }

  cout << nd << ' ' << orr << ' ' << xr << '\n';
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