#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const ll inf = 1e18;

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

void solve() {
  ll x, y; cin >> x >> y;

  for (int k = 0; k <= 60; k++) {
    ll val = (1ll << k);
    if (val >= x) {
      int d = val - x;
      ll a = (x + d) + (y + d);
      ll b = (x + d) ^ (y + d);
      if (a == b) {
        assert(d <= inf);
        cout << d << '\n';
        return;
      }
    }

    if (val >= y) {
      int d = val - y;
      ll a = (x + d) + (y + d);
      ll b = (x + d) ^ (y + d);
      if (a == b) {
        assert(d <= inf);
        cout << d << '\n';
        return;
      }
    }
  }  

  cout << -1 << '\n';
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