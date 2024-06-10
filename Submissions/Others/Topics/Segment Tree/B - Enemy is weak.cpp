#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  pair<int, int> left_right[n + 1];
  o_set<int> se1, se2;
  for(int i = 1; i <= n; i++) {
    int x = se1.order_of_key(a[i]);
    left_right[i].first = x;
    se1.insert(a[i]);
  }

  for(int i = n; i >= 1; i--) {
    int x = se2.order_of_key(-a[i]);
    left_right[i].second = x;
    se2.insert(-a[i]);
  }

  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += (1ll * left_right[i].first * left_right[i].second);
  }
  cout << ans << '\n';

  return 0;
}