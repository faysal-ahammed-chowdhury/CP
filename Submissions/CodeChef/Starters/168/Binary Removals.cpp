#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n, x, k; cin >> n >> x >> k;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    char c; cin >> c;
    a[i] = c - '0';
  }

  o_set<pair<int, int>> se;
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    se.insert({a[i], i});
    ans += se.order_of_key({a[i], 2e9});
  }

  if (ans <= x and ans % k == 0) cout << 1 << '\n';
  else cout << 2 << '\n';
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