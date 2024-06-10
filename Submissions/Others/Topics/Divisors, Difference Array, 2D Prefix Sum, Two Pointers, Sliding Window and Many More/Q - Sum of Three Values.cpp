#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  int a[n + 1];
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int need = x - (a[i] + a[j]);
      if (mp.find(need) != mp.end()) {
        for (auto k : mp[need]) {
          if (k != i and k != j) {
            cout << i << ' ' << j << ' ' << k << '\n';
            return 0;
          }
        }
      }
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}