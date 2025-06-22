#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }
void CLEAR(ll &N, int pos) { (N &= ~(1ll << pos)); }

void solve() {
  ll n, k; cin >> n >> k;
  vector<ll> v;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll x; cin >> x;
    ans += __builtin_popcountll(x);
    while (true) {
      int pos = -1;
      for (int k = 0; k < 60; k++) {
        if (!CHECK(x, k)) {
          pos = k;
          SET(x, k);
          break;
        }
      }
      if (pos == -1) break;
      v.push_back(1ll << pos);
    }
  }
  sort(v.begin(), v.end());

  for (auto x : v) {
    // cout << x << '\n';
    if (x <= k) {
      k -= x;
      ans++;
    }
  }
  cout << ans << '\n';
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