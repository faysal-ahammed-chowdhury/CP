#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  map<int, int> mp1, mp2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp1[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    mp2[b[i]]++;
  }
  if (mp1 != mp2) {
    cout << "NO\n";
    return;
  }
  o_set<int> se1, se2;
  long long ans1 = 0, ans2 = 0;
  for(int i = 1; i <= n; i++) {
    se1.insert(a[i]);
    ans1 += se1.order_of_key(a[i]);
    se2.insert(b[i]);
    ans2 += se2.order_of_key(b[i]);
  }
  long long d = abs(ans1 - ans2);
  if (d % 2 == 0) cout << "YES\n";
  else cout << "NO\n";
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