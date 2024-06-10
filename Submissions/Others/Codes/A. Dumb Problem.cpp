#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int less[n + 1], greater[n + 1];
  o_set<int> se;
  for(int i = 1; i <= n; i++) {
    less[i] = se.order_of_key(a[i]);
    se.insert(a[i]);
  }

  se.clear();
  for(int i = n; i >= 1; i--) {
    greater[i] = se.order_of_key(a[i]);
    se.insert(a[i]);
  }

  for(int i = 1; i <= n; i++) {
    if(less[i] * greater[i] > 0) {
      cout << "Yes\n";
      for(int j = i; j >= 1; j--) {
        if(a[j] < a[i]) {
          cout << j << ' ';
          break;
        }
      }
      cout << i << ' ';
      for(int j = i; j <= n; j++) {
        if(a[j] < a[i]) {
          cout << j << '\n';
          break;
        }
      }
      return;
    }
  }
  cout << "No\n" << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}