#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  vector<int> v;
  for (auto [x, y] : mp) {
    v.push_back(y);
  }

  int x = v.size();

  long long ans = 0;
  for (int i = 0; i < x; i++) {
    for (int j = i + 1; j < x; j++) {
      ans += 1ll * v[i] * v[j];
    }
  }

  cout << ans << '\n';

  return 0;
}