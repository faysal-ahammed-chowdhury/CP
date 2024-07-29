#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n; cin >> n;
  o_set<int> se;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    se.insert(x);
  }
  vector<int> ans;
  for (int k = 1; k <= 40; k++) {
    if (se.size() == 1 and *se.begin() == 0) break;
    set<int> tmp;
    int x = ((*se.begin() + *se.rbegin())) / 2;
    for (auto val : se) {
      tmp.insert(abs(val - x));
    }
    se.clear();
    for (auto val : tmp) se.insert(val);
    ans.push_back(x);
  }
  bool ok = ans.size() <= 40 and *se.begin() == 0 and se.size() == 1;
  if (!ok) {
    cout << -1 << '\n';
    return;
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' '; cout << '\n';
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