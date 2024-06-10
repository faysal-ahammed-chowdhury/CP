#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    o_set<int> se, se2;
    set<int> no_move;
    for (int i = 1; i <= n; i++) {
      int x = se.order_of_key(a[i]);
      if (x == 0) {
        no_move.insert(a[i]);
      };
      se.insert(a[i]);
    }

    se.clear();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x = se.order_of_key(a[i]);
      int y = se2.order_of_key(a[i]);
      if (x == y and x != 0) ans++;
      se.insert(a[i]);
      if (no_move.find(a[i]) != no_move.end()) {
        se2.insert(a[i]);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}