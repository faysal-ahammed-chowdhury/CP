#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  pair<pair<int, int>, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first.second >> a[i].first.first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  int ans[n + 1];
  map<int, int> mp;
  o_set<pair<int, int>> se;
  for (int i = 1; i <= n; i++) {
    ans[a[i].second] = se.order_of_key({a[i].first.second, 1e9});
    mp[a[i].first.second]++;
    se.insert({a[i].first.second, mp[a[i].first.second]});
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}