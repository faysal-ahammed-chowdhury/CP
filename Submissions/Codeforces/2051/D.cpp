#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n; ll x, y; cin >> n >> x >> y;
  int a[n + 1];
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (x >= sum) {
    cout << 0 << '\n';
    return;
  }

  ll mn = sum - y, mx = sum - x;

  // cout << mn << ' ' << mx << '\n';

  o_set<pair<ll, ll>> se;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll x = mx - a[i], y = mn - a[i];
    // cout << x << ' ' << y << '\n';
    ans += se.order_of_key({x, i}) - se.order_of_key({y, 0});
    se.insert({a[i], i});
  } 
  cout << ans << '\n';
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