#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;

const int N = 1e5 + 9, inf = 1e18;

void solve() {
  int n, k; cin >> n >> k;
  o_set<array<int, 3>> se;
  for (int i = 1; i <= n; i++) {
    int l, r, real; cin >> l >> r >> real;
    se.insert({real, l, r});
  }

  int ans = k;
  while (!se.empty()) {
    auto [mx, _, __] = *(--se.end());
    priority_queue<array<int, 4>> pq;
    vector<array<int, 3>> v;
    for (auto [real, l, r] : se) {
      if (real == mx) {
        v.push_back({real, l, r});
        pq.push({real, l, r, real});
      }
    }

    for (auto [real, l, r] : v) {
      se.erase({real, l, r});
    }

    while (!pq.empty()) {
      auto [real, l, r, mx] = pq.top(); pq.pop();
      if (l <= k and k <= r) ans = max(ans, mx);
      // cout << real << ' ' << l << ' ' << r << '\n';
      int idx1 = se.order_of_key({l, -inf, -inf});
      int idx2 = se.order_of_key({r, inf, inf});
      // cout << idx1 << ' ' << idx2 << ' ' << se.size() << '\n';
      v.clear();
      // cout << "here:\n";
      for (int j = idx1; j < idx2; j++) {
        auto [val, x, y] = *se.find_by_order(j);
        // cout << x << ' ' << y << ' ' << val << '\n';
        pq.push({val, x, y, mx});
        v.push_back({val, x, y});
      }
      for (auto [val, x, y] : v) {
        se.erase({val, x, y});
      }
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