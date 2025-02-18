#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
const int N = 2e5 + 9, mod = 998244353, inf = 1e9;

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int inverse(int x) {
  return power(x, mod - 2, mod);
}

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1], b[n + 1];
  o_set<pair<int, int>> se1, se2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se1.insert({a[i], i});
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    se2.insert({b[i], i});
  }

  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans = 1ll * ans * min((*se1.find_by_order(i)).first, (*se2.find_by_order(i)).first) % mod;
  }

  cout << ans << ' ';
  // for (auto [x, idx] : se1) {
  //   cout << "(" << x << ", " << idx << ")" << ' ';
  // }
  // cout << '\n';
  // for (auto [x, idx] : se2) {
  //   cout << "(" << x << ", " << idx << ")" << ' ';
  // }
  // cout << ans << '\n';


  while (q--) {
    int type, idx; cin >> type >> idx;
    if (type == 1) {
      int old_value = a[idx];
      int new_value = ++a[idx];
      int old_idx = se1.order_of_key({old_value, inf}) - 1;
      auto it1 = se1.find_by_order(old_idx);
      auto it2 = se2.find_by_order(old_idx);
      int baad = min((*it1).first, (*it2).first);
      int rm_idx = (*it1).second;
      se1.erase(it1);
      se1.insert({new_value, rm_idx});
      int new_idx = se1.order_of_key({new_value, 0});
      it1 = se1.find_by_order(new_idx);
      it2 = se2.find_by_order(new_idx);
      int add = min((*it1).first, (*it2).first);

      ans = 1ll * ans * inverse(baad) % mod;
      ans = 1ll * ans * add % mod;
      cout << ans << ' ';
    }
    else {
      int old_value = b[idx];
      int new_value = ++b[idx];
      int old_idx = se2.order_of_key({old_value, inf}) - 1;

      auto it1 = se2.find_by_order(old_idx);
      auto it2 = se1.find_by_order(old_idx);
      int baad = min((*it1).first, (*it2).first);
      int rm_idx = (*it1).second;
      se2.erase(it1);
      se2.insert({new_value, rm_idx});
      int new_idx = se2.order_of_key({new_value, 0});
      it1 = se2.find_by_order(new_idx);
      it2 = se1.find_by_order(new_idx);
      int add = min((*it1).first, (*it2).first);

      ans = 1ll * ans * inverse(baad) % mod;
      ans = 1ll * ans * add % mod;
      cout << ans << ' ';
    }
  }
  cout << '\n';
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