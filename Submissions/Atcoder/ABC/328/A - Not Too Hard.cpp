#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  int ans = 0;
  for (auto x : a) {
    if (x <= k) {
      ans += x;
    }
  }
  cout << ans << '\n';

  return 0;
}