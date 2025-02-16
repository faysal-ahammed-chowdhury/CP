#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> v;
  ll ans = 0;
  while (n >= k) {
    int mid = (n + 1) / 2;
    if (n % 2 == 1) {
      int sz = v.size();
      ll cur = 1ll * mid * (1ll << sz);
      for (auto x : v) {
        cur += 1ll * x * (1ll << (sz - 1));
      }
      // cout << mid << ' ' << cur << '\n';
      ans += cur;
      v.push_back(mid);
    }
    else {
      v.push_back(mid);
    }
    n /= 2;
  }

  cout << ans << '\n';
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