#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 9, inf = 1e9;
int n, mx, q, Q[N];
map<int, vector<int>> mp;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> mx >> q;
  for (int i = 1; i <= q; i++) {
    cin >> Q[i];
    mp[Q[i]].push_back(i);
  }

  int ans = 0;
  set<int> se;
  o_set<array<int, 2>> nxt_occ;
  map<int, int> mp2;
  for (int i = 1; i <= q; i++) {
    if (se.find(Q[i]) != se.end()) {
      // cout << "IN: " << Q[i] << ", OUT: " << val << ',' << nxt << '\n';
      nxt_occ.erase({mp2[Q[i]], Q[i]});
      auto it = upper_bound(mp[Q[i]].begin(), mp[Q[i]].end(), i);
      if (it == mp[Q[i]].end()) {
        nxt_occ.insert({inf, Q[i]});
        mp2[Q[i]] = inf;
      }
      else {
        nxt_occ.insert({*it, Q[i]});
        mp2[Q[i]] = *it;
      }
      continue;
    }
    if (se.size() < n) {
      // cout << "IN: " << Q[i] << '\n';
      ans++;
      se.insert(Q[i]);
      auto it = upper_bound(mp[Q[i]].begin(), mp[Q[i]].end(), i);
      if (it == mp[Q[i]].end()) {
        nxt_occ.insert({inf, Q[i]});
        mp2[Q[i]] = inf;
      }
      else {
        nxt_occ.insert({*it, Q[i]});
        mp2[Q[i]] = *it;
      }
    }
    else {
      ans++;
      int nxt = (*nxt_occ.rbegin())[0];
      int val = (*nxt_occ.rbegin())[1];
      nxt_occ.erase(--nxt_occ.end());
      // cout << "IN: " << Q[i] << ", OUT: " << val << ',' << nxt << '\n';
      se.erase(val);
      se.insert(Q[i]);
      auto it = upper_bound(mp[Q[i]].begin(), mp[Q[i]].end(), i);
      if (it == mp[Q[i]].end()) {
        nxt_occ.insert({inf, Q[i]});
        mp2[Q[i]] = inf;
      }
      else {
        nxt_occ.insert({*it, Q[i]});
        mp2[Q[i]] = *it;
      }
    }
    // for (auto x : se) {
    //   cout << x << ' ';
    // }
    // cout << '\n';
  }

  cout << ans << '\n';

  return 0;
}