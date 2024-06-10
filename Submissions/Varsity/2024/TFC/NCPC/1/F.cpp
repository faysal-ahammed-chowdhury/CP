#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  vector<pair<int, int>> a;
  map<int, int> mp;
  o_set<pair<int, int>> st, en;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    st.insert({x, mp[x]++});
    en.insert({y, mp[y]++});
    a.push_back({x, y});
  }

  int mx = 0;
  for (auto [x, y] : a) {
    int ans = n;
    auto it = st.lower_bound({x + k + 1 , 0});
    if (it != st.end()) {
      int idx = st.order_of_key({(*it).first, (*it).second});
      idx = n - idx;
      ans -= idx;
    }

    it = en.lower_bound({x , 0});
    if (it != en.end()) {
      int idx = en.order_of_key({(*it).first, (*it).second});
      ans -= idx;
    }
    else {
      ans -= n;
    }
    mx = max(ans, mx);
  }

  for (auto [x, y] : a) {
    int ans = n;
    auto it = st.lower_bound({y + k + 1 , 0});
    if (it != st.end()) {
      int idx = st.order_of_key({(*it).first, (*it).second});
      idx = n - idx;
      ans -= idx;
    }

    it = en.lower_bound({y , 0});
    if (it != en.end()) {
      int idx = en.order_of_key({(*it).first, (*it).second});
      ans -= idx;
    }
    else {
      ans -= n;
    }
    mx = max(ans, mx);
  }

  cout << mx << '\n';

  return 0;
}