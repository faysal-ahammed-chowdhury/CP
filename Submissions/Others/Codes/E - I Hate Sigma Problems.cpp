#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x].push_back(i);
  }
  long long ans = 0;
  for (auto [_, v] : mp) {
    int last = 0;
    for (auto x : v) {
      ans += 1ll * (x - last) * (n - x + 1);
      last = x;
    }
  }
  cout << ans << '\n';

  return 0;
}