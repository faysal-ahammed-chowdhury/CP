#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<pair<int, ll>> ans;
  for (int i = 1; i <= n; i++) {
    ll x; cin >> x;
    int msb = __lg(x) + 1;
    ll y = (1ll << msb);
    ll need = y - x;
    ans.push_back({i, need});
    assert(need <= x);
  }

  cout << ans.size() << '\n';
  for (auto [i, x] : ans) {
    cout << i << ' ' << x << '\n';
  }
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