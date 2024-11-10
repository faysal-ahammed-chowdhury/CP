#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int cs;
void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  o_set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(i);
  }

  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int i, x; cin >> i >> x;
    int idx = *se.find_by_order(i);
    int idx1 = -1, idx2 = -1;
    if (i - 1 >= 0) idx1 = *se.find_by_order(i - 1);
    if (i + 1 < se.size()) idx2 = *se.find_by_order(i + 1);

    // cout << idx1 << ' ' << idx << ' ' << idx2 << '\n';

    a[idx] = x;
    if (idx1 != -1 and idx2 != -1 and x == a[idx1] and x == a[idx2]) {
      se.erase(idx1);
      se.erase(idx2);
    }
    else if (idx1 != -1 and x == a[idx1]) {
      se.erase(idx);
    }
    else if (idx2 != -1 and x == a[idx2]) {
      se.erase(idx);
    }
    cout << se.size() << '\n';
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