#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

map<int, int> mp;
int fun(int x) {
  int ans = 0;
  while (x > 0) {
    ans += mp[x % 10];
    x /= 10;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  o_set<int> se;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    se.insert(x);
    while (x > 0) {
      mp[x % 10]++;
      x /= 10;
    }
  }

  while (q--) {
    char c; int k; cin >> c >> k;
    if (c == '+') {
      if (se.find(k) == se.end()) {
        se.insert(k);
        while (k > 0) {
          mp[k % 10]++;
          k /= 10;
        }
      }
      else {
        se.erase(k);
        while (k > 0) {
          mp[k % 10]--;
          k /= 10;
        }
      }
    }
    else if (c == '-') {
      if (se.size() >= k) {
        auto x = se.find_by_order(k - 1);
        se.erase(x);
        int val = *x;
        while (val > 0) {
          mp[val % 10]--;
          val /= 10;
        }
      }
    }
    else {
      if (se.find(k) != se.end()) {
        cout << fun(k) << '\n';
      }
      else {
        cout << -1 << '\n';
      }
    }
  }

  return 0;
}