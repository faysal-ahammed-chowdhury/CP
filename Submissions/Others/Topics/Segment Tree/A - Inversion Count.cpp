#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

// @author: faysalahammedchowdhury

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  o_set<int> se;
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    se.insert(a[i]);
    ans += se.order_of_key(a[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}