#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int k; ll x; cin >> k >> x;

  ll a = (1ll << (k + 1)) - x;
  ll b = x;

  vector<int> ans;
  while (b != (1ll << k)) {
    if (a < b) {
      b -= a;
      a *= 2;
      ans.push_back(2);
    }
    else {
      a -= b;
      b *= 2;
      ans.push_back(1);
    }
  }
  reverse(ans.begin(), ans.end());
  
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
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