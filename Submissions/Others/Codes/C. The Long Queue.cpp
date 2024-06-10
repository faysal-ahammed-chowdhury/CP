#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  map<string, multiset<pair<int, int>>> mp;
  o_set<pair<string, int>> se;
  map<string, int> cnt;
  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      string name; int rank, id; cin >> name >> rank >> id;
      mp[name].insert(make_pair(rank, -id));
      cnt[name]++;
      se.insert({name, cnt[name]});
    }
    else {
      string name; cin >> name;
      auto get = *mp[name].begin();
      cout << get.first << ' ' << -get.second << '\n';
      mp[name].erase(mp[name].begin());
      cout << se.order_of_key({name, 1}) << '\n';
      se.erase({name, cnt[name]});
      cnt[name]--;
    }
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