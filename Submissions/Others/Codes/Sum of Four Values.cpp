#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<int, pair<int, int>> mp;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int need = x - a[i] - a[j];
      if (mp.find(need) != mp.end()) {
        cout << mp[need].first << ' ' << mp[need].second << ' ' << i << ' ' << j << '\n';
        return 0;
      }
    }

    for (int z = 1; z < i; z ++) {
      mp[a[i] + a[z]] = {z, i};
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}