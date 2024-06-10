#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int val; cin >> val;
    mp[val]++;
  }

  int ans = mp[x];
  for (int i = 0; i < x; i++) {
    if (mp.find(i) == mp.end()) {
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}