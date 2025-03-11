#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

void solve() {
  int x; cin >> x;
  int msb = __lg(x);
  int y = 0;
  int idx = -1;
  for (int k = 0; k <= msb; k++) {
    if (!CHECK(x, k)) {
      SET(y, k);
    }
    else if (k != msb) idx = k;
  }

  if (idx != -1) {
    SET(y, idx);
  }

  int z = x ^ y;
  int sum = x + y + z;
  int mn = min({x, y, z});
  int mx = max({x, y, z});
  int other = sum - mx - mn;
  if (other + mn > mx) cout << y << '\n';
  else cout << -1 << '\n';

  assert(y < x);
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